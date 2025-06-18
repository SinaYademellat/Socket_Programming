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
public:

    ChartViewHelper();
    char mode = 'L'; // L = Line :)
    void PlotChart(QFrame *chartFrame_input , QList<int> DataForPlotIs);



};

#endif // CHARTVIEWHELPER_H
