#include "chartviewhelper.h"
#include <QBarCategoryAxis>

#include <QList>

#include <QtCharts/QAreaSeries>
#include <QtCharts/QLineSeries>



ChartViewHelper::ChartViewHelper(){};

// --------------------

void ChartViewHelper::setupChartAppearance (QChart *chart_input, QFrame *chartFrame_input)
{
    // chart->setAnimationOptions(QChart::SeriesAnimations);

    chart_input->setTitleBrush (QBrush (QColor (0xFFA500)));
    chart_input->setBackgroundBrush (QBrush (QColor (0x1E1E1E)));

    chart_input->createDefaultAxes ();
    auto tmp1 = chart_input->axes (Qt::Horizontal);
    QAbstractAxis *axisX = tmp1.first ();
    auto tmp2 = chart_input->axes (Qt::Vertical);
    QAbstractAxis *axisY = tmp2.first ();
    axisX->setLinePen (QPen (Qt::green));
    axisX->setLabelsBrush (QBrush (Qt::green));
    axisY->setLinePen (QPen (Qt::green));
    axisY->setLabelsBrush (QBrush (Qt::green));

    QChartView *chartView = new QChartView (chart_input);
    chartView->setRenderHint (QPainter::Antialiasing);
    chartFrame_input->layout ()->addWidget (chartView);
}


int ChartViewHelper::find_data_conect (int curentindex,  QList<int> data, int treshould)
{
    int preindex  = curentindex - 1;
    while (true)
    {
        if(preindex<0)
        {
            return -1;
        }

        if(data[preindex]<=treshould)
        {
            return preindex;
        }
        else
        {
            preindex -= 1;
        }
    }
}


float ChartViewHelper::findX (float x0, float y0,
    float x1, float y1,
    float Y)
{
    float m  = (y1 -y0)/(x1-x0);

    return((Y-y0 + (m*x0))/m);
}


// -----------------------  << Min >>
//---------- (Bar)
void ChartViewHelper::_plotChartWithMinFilter_BarChar (QChart *chart_input,
    const QList<int>& DataForPlotIs,
    int low_bound, int low_colorCode ){
    // Bar chart
    QBarSet *set_N = new QBarSet ("Normal");
    QBarSet *set_L = new QBarSet ("Min");

    for(int i = 0 ; i< DataForPlotIs.size () ; i++)
    {
        int curentDataIs = DataForPlotIs[i];

        if(curentDataIs <= low_bound)
        {
            *set_L<< curentDataIs;
            *set_N<< 0;
        }
        else
        {
            *set_L<< 0;
            *set_N<< curentDataIs;
        }
    }

    set_N->setBrush (Qt::white);
    set_L->setBrush (this->colorsFor_colorCombo_IS[low_colorCode]);
    QBarSeries *series = new QBarSeries ();
    series->append (set_L);
    series->append (set_N);
    chart_input->addSeries (series);
}
//---------- (Line)
// setMask
void ChartViewHelper::appendMaskedSeriesByLowerBound (QList<float> &HitLine_X,
    QList<float> &X_low, QList<int> &Y_low,
    QLineSeries *upperMask, QLineSeries *lowMask,
    int Threshold_min)
{
    int i=0; int j=0; int N=0;
    while((i<X_low.size ()) && (j<HitLine_X.size ()) )
    {
        if(X_low[i] < HitLine_X[j])
        {
            qDebug ()<< N <<" ) " <<X_low[i] <<" , "<<Y_low[i];

            upperMask->append (X_low[i], Y_low[i]);
            lowMask->append (X_low[i], 0);

            i+=1;
        }
        else
        if(X_low[i] == HitLine_X[j])
        {
            qDebug ()<< N <<" ) " <<X_low[i] <<" , "<<Y_low[i];

            upperMask->append (X_low[i], Y_low[i]);
            lowMask->append (X_low[i], 0);

            i+=1;
            j+=1;
        }
        else
        {
            qDebug ()<< N <<" ) " <<HitLine_X[j]<<" , "<<Threshold_min;

            upperMask->append (HitLine_X[j], Threshold_min);
            lowMask->append (HitLine_X[j], 0);

            j+=1;
        }
        N+=1;
    }

    while(i<X_low.size ())
    {
        qDebug ()<< N <<" ) " <<X_low[i]<<" , "<<Y_low[i];

        upperMask->append (X_low[i], Y_low[i]);
        lowMask->append (X_low[i], 0);

        i+=1;
        N+=1;
    }

    while(j<HitLine_X.size ())
    {
        qDebug ()<< N <<" ) " <<HitLine_X[j]<<" , "<<Threshold_min;

        upperMask->append (HitLine_X[j], Threshold_min);
        lowMask->append (HitLine_X[j], 0);

        j+=1;
        N+=1;
    }
}
// plot
void ChartViewHelper::_plotChartWithMinFilter_LineChar (QChart *chart_input,
    const QList<int> &DataForPlotIs,
    int low_bound, int low_colorCode)
{
    // Line chart
    QLineSeries *mainSeries = new QLineSeries ();
    QLineSeries *baseLine = new QLineSeries ();

    //candidate
    QList<float>candidateX_Line; candidateX_Line.clear ();
    QList<float>candidateX; QList<int>candidate_Y;


    for (int i = 1; i < DataForPlotIs.size (); ++i)
    {
        int preData     = DataForPlotIs[i-1];
        int curentData  = DataForPlotIs[i];

        if(((low_bound >= preData) && (low_bound <= curentData)) || (((low_bound >= curentData) && (low_bound <= preData))))
        {
            float newData = findX (i-1, preData, i, curentData, low_bound);
            candidateX_Line.append (newData);
        }
    }


    for (int i = 0; i < DataForPlotIs.size (); ++i)
    {
        int value = DataForPlotIs[i];
        mainSeries->append (i, value);
        baseLine->append (i, low_bound);
        // ----------------
        if(value<=low_bound)
        {
            candidateX.append (i);
            candidate_Y.append (value);
        }
    }


    /////////////////////////
    QLineSeries *upperSeries = new QLineSeries ();
    QLineSeries *lowMaskSeries = new QLineSeries ();

    this->appendMaskedSeriesByLowerBound (candidateX_Line, candidateX, candidate_Y, upperSeries, lowMaskSeries, low_bound);
    /////////////////////////


    mainSeries->setPen (QPen (Qt::white, 2));
    baseLine->setPen (QPen (this->colorsFor_colorCombo_IS[low_colorCode], 1));

    QAreaSeries *areaUnderLow = new QAreaSeries (upperSeries, lowMaskSeries);
    areaUnderLow->setColor (this->colorsFor_colorCombo_IS[low_colorCode]);

    chart_input->addSeries (mainSeries);
    chart_input->addSeries (baseLine);
    chart_input->addSeries (areaUnderLow);
}

// -----------------------  << Max >>
//---------- (Bar)
void ChartViewHelper::_plotChartWithMaxFilter_BarChar (QChart *chart_input,
    const QList<int> &DataForPlotIs,
    int Up_bound, int Up_colorCode)
{
    // Bar chart

    QBarSet *set_U = new QBarSet ("Max");
    QBarSet *set_N = new QBarSet ("Normal");


    for(int i = 0 ; i< DataForPlotIs.size () ; i++)
    {
        int curentDataIs = DataForPlotIs[i];

        if(curentDataIs >= Up_bound)
        {
            *set_U<< curentDataIs;
            *set_N<< 0;
        }
        else
        {
            *set_U<< 0;
            *set_N<< curentDataIs;
        }
    }

    set_U->setBrush (this->colorsFor_colorCombo_IS[Up_colorCode]);
    set_N->setBrush (Qt::white);

    QBarSeries *series = new QBarSeries ();

    series->append (set_N);
    series->append (set_U);

    chart_input->addSeries (series);
}

//---------- (Line)
// setMask

void ChartViewHelper::appendMaskedSeriesByUpperBound (QList<float> &HitLine_X,
    QList<float> &X_low, QList<int> &Y_low,
    QLineSeries *upperMask, QLineSeries *lowMask,
    int Threshold_max)
{
    int i=0; int j=0; int N=0;
    while((i<X_low.size ()) && (j<HitLine_X.size ()) )
    {
        if(X_low[i] < HitLine_X[j])
        {
            qDebug ()<< N <<" ) " <<X_low[i] <<" , "<<Y_low[i];

            upperMask->append (X_low[i], Y_low[i]);
            lowMask->append (X_low[i], Threshold_max);

            i+=1;
        }
        else
        if(X_low[i] == HitLine_X[j])
        {
            qDebug ()<< N <<" ) " <<X_low[i] <<" , "<<Y_low[i];

            upperMask->append (X_low[i], Y_low[i]);
            lowMask->append (X_low[i], Threshold_max);

            i+=1;
            j+=1;
        }
        else
        {
            qDebug ()<< N <<" ) " <<HitLine_X[j]<<" , "<<Threshold_max;

            upperMask->append (HitLine_X[j], Threshold_max);
            lowMask->append (HitLine_X[j], Threshold_max);

            j+=1;
        }
        N+=1;
    }

    while(i<X_low.size ())
    {
        qDebug ()<< N <<" ) " <<X_low[i]<<" , "<<Y_low[i];

        upperMask->append (X_low[i], Y_low[i]);
        lowMask->append (X_low[i], Threshold_max);

        i+=1;
        N+=1;
    }

    while(j<HitLine_X.size ())
    {
        qDebug ()<< N <<" ) " <<HitLine_X[j]<<" , "<<Threshold_max;

        upperMask->append (HitLine_X[j], Threshold_max);
        lowMask->append (HitLine_X[j], Threshold_max);

        j+=1;
        N+=1;
    }
}

// plot
void ChartViewHelper::_plotChartWithMaxFilter_LineChar (QChart *chart_input,
    const QList<int> &DataForPlotIs,
    int Up_bound, int Up_colorCode)
{
    // Line chart
    QLineSeries *mainSeries = new QLineSeries ();
    QLineSeries *baseLine = new QLineSeries ();




    QList<float>candidateX_Line; candidateX_Line.clear ();
    QList<float>candidate_X; candidate_X.clear ();
    QList<int>candidate_Y; candidate_Y.clear ();


    for (int i = 1; i < DataForPlotIs.size (); ++i)
    {
        int preData     = DataForPlotIs[i-1];
        int curentData  = DataForPlotIs[i];

        if(((Up_bound >= preData) && (Up_bound <= curentData)) || (((Up_bound >= curentData) && (Up_bound <= preData))))
        {
            float newData = findX (i-1, preData, i, curentData, Up_bound);
            candidateX_Line.append (newData);
        }
    }


    for (int i = 0; i < DataForPlotIs.size (); ++i)
    {
        int value = DataForPlotIs[i];
        mainSeries->append (i, value);
        baseLine->append (i, Up_bound);
        // ----------------
        if(value>=Up_bound)
        {
            candidate_X.append (i);
            candidate_Y.append (value);
        }
    }


    ////////////////////////////////////
    QLineSeries *upperSeries = new QLineSeries ();
    QLineSeries *lowMaskSeries = new QLineSeries ();
    this->appendMaskedSeriesByUpperBound (candidateX_Line, candidate_X, candidate_Y, upperSeries, lowMaskSeries, Up_bound);
    /////////////////////////

    mainSeries->setPen (QPen (Qt::white, 2));
    baseLine->setPen (QPen (this->colorsFor_colorCombo_IS[Up_colorCode], 1));

    QAreaSeries *areaUnderLow = new QAreaSeries (upperSeries, lowMaskSeries);
    areaUnderLow->setColor (this->colorsFor_colorCombo_IS[Up_colorCode]);

    chart_input->addSeries (mainSeries);
    chart_input->addSeries (baseLine);
    chart_input->addSeries (areaUnderLow);
}

// -----------------------  << Both >>

void ChartViewHelper::_plotChartWithMin_and_MaxFilte_BarChar (QChart *chart_input,
    const QList<int> &DataForPlotIs,
    int low_bound, int low_colorCode,
    int Up_bound, int Up_colorCode)
{
    // Bar chart
    QBarSet *set_U = new QBarSet ("Max");
    QBarSet *set_N = new QBarSet ("Normal");
    QBarSet *set_L = new QBarSet ("Min");


    for(int i = 0 ; i< DataForPlotIs.size () ; i++)
    {
        int curentDataIs = DataForPlotIs[i];

        if(curentDataIs <= low_bound)
        {
            *set_L<< curentDataIs;
            *set_U<< 0;
            *set_N<< 0;
        }
        else
        if(curentDataIs >= Up_bound)
        {
            *set_L<< 0;
            *set_U<< curentDataIs;
            *set_N<< 0;
        }
        else
        {
            *set_L<< 0;
            *set_U<< 0;
            *set_N<< curentDataIs;
        }
    }

    set_U->setBrush (this->colorsFor_colorCombo_IS[Up_colorCode]);
    set_N->setBrush (Qt::white);
    set_L->setBrush (this->colorsFor_colorCombo_IS[low_colorCode]);

    QBarSeries *series = new QBarSeries ();

    series->append (set_L);
    series->append (set_N);
    series->append (set_U);

    chart_input->addSeries (series);
}

void ChartViewHelper::_plotChartWithMin_and_MaxFilte_LineChar (QChart *chart_input,
    const QList<int> &DataForPlotIs,
    int low_bound, int low_colorCode,
    int Up_bound, int Up_colorCode){
    // Line chart
    QLineSeries *mainSeries = new QLineSeries ();

    // Up
    QLineSeries *baseLine_UP = new QLineSeries ();

    QList<float>CandidX_Line_Up; CandidX_Line_Up.clear ();
    QList<float>CandidX_Up; CandidX_Up.clear ();
    QList<int>CandidY_Up; CandidY_Up.clear ();

    // low
    QLineSeries *baseLine_low = new QLineSeries ();

    QList<float>CandidX_Line_low; CandidX_Line_low.clear ();
    QList<float>CandidX_low; CandidX_low.clear ();
    QList<int>CandidY_low; CandidY_low.clear ();

    // ----------------

    for (int i = 1; i < DataForPlotIs.size (); ++i)
    {
        int preData     = DataForPlotIs[i-1];
        int curentData  = DataForPlotIs[i];

        // >>>>>>> Up
        if(((Up_bound >= preData) && (Up_bound <= curentData)) || (((Up_bound >= curentData) && (Up_bound <= preData))))
        {
            float newData = findX (i-1, preData, i, curentData, Up_bound);
            CandidX_Line_Up.append (newData);
        }

        // >>>>>>> Low
        if(((low_bound >= preData) && (low_bound <= curentData)) || (((low_bound >= curentData) && (low_bound <= preData))))
        {
            float newData = findX (i-1, preData, i, curentData, low_bound);
            CandidX_Line_low.append (newData);
        }
    }


    for (int i = 0; i < DataForPlotIs.size (); ++i)
    {
        int value = DataForPlotIs[i];

        mainSeries->append (i, value);

        baseLine_UP->append (i, Up_bound);
        baseLine_low->append (i, low_bound);

        // ----------------
        if(value>=Up_bound)
        {
            CandidX_Up.append (i);
            CandidY_Up.append (value);
        }

        // ----------------
        if(value<=low_bound)
        {
            CandidX_low.append (i);
            CandidY_low.append (value);
        }
    }

    // ----------------

    ////////////////////////////////////

    //UP
    QLineSeries *upperSeries_Up = new QLineSeries ();
    QLineSeries *lowMaskSeries_Up = new QLineSeries ();
    this->appendMaskedSeriesByUpperBound (CandidX_Line_Up, CandidX_Up, CandidY_Up, upperSeries_Up, lowMaskSeries_Up, Up_bound);

    baseLine_UP->setPen (QPen (this->colorsFor_colorCombo_IS[Up_colorCode], 1));

    QAreaSeries *areaUnder_Up = new QAreaSeries (upperSeries_Up, lowMaskSeries_Up);
    areaUnder_Up->setColor (this->colorsFor_colorCombo_IS[Up_colorCode]);

    // Low
    QLineSeries *upperSeries_low = new QLineSeries ();
    QLineSeries *lowMaskSeries_low = new QLineSeries ();
    this->appendMaskedSeriesByLowerBound (CandidX_Line_low, CandidX_low, CandidY_low, upperSeries_low, lowMaskSeries_low, low_bound);

    baseLine_low->setPen (QPen (this->colorsFor_colorCombo_IS[low_colorCode], 1));

    QAreaSeries *areaUnder_low = new QAreaSeries (upperSeries_low, lowMaskSeries_low);
    areaUnder_low->setColor (this->colorsFor_colorCombo_IS[low_colorCode]);
    /////////////////////////

    mainSeries->setPen (QPen (Qt::white, 2));

    chart_input->addSeries (mainSeries);

    chart_input->addSeries (baseLine_UP);
    chart_input->addSeries (baseLine_low);

    chart_input->addSeries (areaUnder_Up);
    chart_input->addSeries (areaUnder_low);
}

// ++++++++++++++++++++++
void ChartViewHelper::PlotChart (QFrame *chartFrame, const QList<int> &DataForPlotIs )
{
    QChart *chart = new QChart ();

    if (this->mode == ChartMode::Bar)
    {
        // Bar chart
        QBarSet *set = new QBarSet ("");
        for(int i=0; i<DataForPlotIs.size () ; i++)
        {
            *set << DataForPlotIs[i];
        }
        QBarSeries *series = new QBarSeries ();
        series->append (set);
        chart->addSeries (series);
    }
    else
    {
        // Line chart
        QLineSeries *series = new QLineSeries ();
        for(int i=0; i<DataForPlotIs.size () ; i++)
        {
            *series <<QPointF (i, DataForPlotIs[i]);
        }
        chart->addSeries (series);
    }

    this->setupChartAppearance (chart, chartFrame);
}
// -------------------------------
void ChartViewHelper::plotChartWithMinFilter (QFrame *chartFrame,
    const QList<int>& data,
    int minValue, int minColor)
{
    QChart *chart = new QChart ();

    if (this->mode ==ChartMode::Bar)
    {
        this->_plotChartWithMinFilter_BarChar (chart, data, minValue, minColor);
    }
    else
    {
        this->_plotChartWithMinFilter_LineChar (chart, data, minValue, minColor);
    }

    this->setupChartAppearance (chart, chartFrame);
}
// ----------------------
void ChartViewHelper::plotChartWithMaxFilter (QFrame *chartFrame,
    const QList<int> &data,
    int maxValue, int maxColor)
{
    QChart *chart = new QChart ();

    if (this->mode ==ChartMode::Bar)
    {
        this->_plotChartWithMaxFilter_BarChar (chart, data, maxValue, maxColor);
    }
    else
    {
        this->_plotChartWithMaxFilter_LineChar (chart, data, maxValue, maxColor);
    }
    this->setupChartAppearance (chart, chartFrame);
}
// ----------------------
void ChartViewHelper::plotChartWithMin_and_MaxFilter (QFrame *chartFrame,
    const QList<int> &data,
    int minValue, int minColor,
    int maxValue, int maxColor)
{
    QChart *chart = new QChart ();

    if (this->mode == ChartMode::Bar)
    {
        this->_plotChartWithMin_and_MaxFilte_BarChar (chart, data, minValue, minColor, maxValue, maxColor );
    }
    else
    {
        this->_plotChartWithMin_and_MaxFilte_LineChar (chart, data, minValue, minColor, maxValue, maxColor );
    }
    this->setupChartAppearance (chart, chartFrame);
}
// ----------------------
