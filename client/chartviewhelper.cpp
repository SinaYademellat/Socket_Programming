#include "chartviewhelper.h"
#include <QBarCategoryAxis>
ChartViewHelper::ChartViewHelper(){};

void ChartViewHelper::PlotChart(QFrame *chartFrame_input , QList<int> DataForPlotIs )
{
    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::SeriesAnimations);

    if (this->mode == 'B')
    {
        // Bar chart
        QBarSet *set = new QBarSet("");

        for(int i=0; i<DataForPlotIs.size() ; i++)
        {
            *set << DataForPlotIs[i];
        }

        QBarSeries *series = new QBarSeries();
        series->append(set);
        chart->addSeries(series);

    } else
    {
        // Line chart
        QLineSeries *series = new QLineSeries();

        for(int i=0; i<DataForPlotIs.size() ; i++)
        {
            *series <<QPointF(i, DataForPlotIs[i]) ;
        }
        chart->addSeries(series);
    }


    chart->setTitleBrush(QBrush(QColor(0xFFA500)));
    chart->setBackgroundBrush(QBrush(QColor(0x1E1E1E)));

    chart->createDefaultAxes();
    auto tmp1 = chart->axes(Qt::Horizontal);
    QAbstractAxis *axisX = tmp1.first();
    auto tmp2 = chart->axes(Qt::Vertical);
    QAbstractAxis *axisY = tmp2.first();
    axisX->setLinePen(QPen(Qt::green));
    axisX->setLabelsBrush(QBrush(Qt::green));
    axisY->setLinePen(QPen(Qt::green));
    axisY->setLabelsBrush(QBrush(Qt::green));

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartFrame_input->layout()->addWidget(chartView);
}
