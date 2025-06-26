#ifndef CHARTVIEWHELPER_H
#define CHARTVIEWHELPER_H

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>


#include <QtWidgets/QFrame>



class ChartViewHelper
{
private:
    int numberIs = 0 ;

    void setupChartAppearance(QChart *chart, QFrame *chartFrame);


    int  find_data_conect(int curentindex, QList<int> data, int treshould);
    float findX(float x0, float y0, float x1 , float y1 ,float Y );

    void appendMaskedSeriesByLowerBound(QList<float>& HitLine_X, QList<float>& X_low, QList<int>&Y_low , QLineSeries *upperMask , QLineSeries *lowMask,int Threshold_min);
    // min
    void _plotChartWithMinFilter_BarChar(QChart *chart_input , const QList<int>& DataForPlotIs ,int low_bound, int low_colorCode );
    void _plotChartWithMinFilter_LineChar(QChart *chart_input , const QList<int>& DataForPlotIs ,int low_bound, int low_colorCode );


    void appendMaskedSeriesByUpperBound(QList<float>& HitLine_X, QList<float>& X_low, QList<int>&Y_low , QLineSeries *upperMask , QLineSeries *lowMask,int Threshold_max);
    // Max
    void _plotChartWithMaxFilter_BarChar(QChart *chart_input , const QList<int>& DataForPlotIs  ,int Up_bound, int Up_colorCode );
    void _plotChartWithMaxFilter_LineChar(QChart *chart_input , const QList<int>& DataForPlotIs ,int Up_bound, int Up_colorCode );

    // Both
    void _plotChartWithMin_and_MaxFilte_BarChar(QChart *chart_input , const QList<int>& DataForPlotIs ,int low_bound, int low_colorCode,int Up_bound, int Up_colorCode);
    void _plotChartWithMin_and_MaxFilte_LineChar(QChart *chart_input , const QList<int>& DataForPlotIs ,int low_bound, int low_colorCode,int Up_bound, int Up_colorCode);


public:

    QList<QColor>  colorsFor_colorCombo_IS = { Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::gray };
    char mode = 'L'; // L = Line :)

    ChartViewHelper();

    void PlotChart(QFrame *chartFrame_input ,  const QList<int>& DataForPlotIs);


    // ---------------------
    void plotChartWithMinFilter(QFrame *chartFrame, const QList<int>& data, int minValue, int minColor);
    void plotChartWithMaxFilter(QFrame *chartFrame, const QList<int>& data, int maxValue, int maxColor);
    void plotChartWithMin_and_MaxFilter(QFrame *chartFrame, const QList<int>& data, int minValue, int minColor,int maxValue, int maxColor);
};

#endif // CHARTVIEWHELPER_H
