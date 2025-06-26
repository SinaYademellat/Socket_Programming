#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QVBoxLayout>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>

#include <QTimer>


#include "basicfunctions.h"
#include "chartviewhelper.h"
#include "clientclass.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_form1_Loggin_clicked();

    void on_pushButton_form2_clicked();

    void on_pushButton_form3_clicked();

    void on_pushButton_form4_Filter_clicked();
    void on_pushButton_form4_Clean_clicked();    


private:

    Ui::MainWindow *ui;

    BasicFunctions mybasicfunctis;
    ChartViewHelper chartTest1 ;
    ClientClassTcp MainClientIs_Global;
    // ---------------------

    // ---------------------
    void creatLoggingPageGui();
    void creat_main_Form_Gui();
    void creat_GUi_Form3and4();

    bool _checkForms();
    bool _check_Ip_Gui();
    bool _check_Port_Gui();
    bool _check_Username_Gui();
    bool _check_Password_Gui();
    bool _canUseDasBord();
    // ---------------------

    // ---------------------
    void updateChart();
    void _Refresh_chart();
    void _SetModeOFChart();

    void _Sampling_Maximum_Ui();
    void _Sampling_Minimum_Ui();
    void _Sampling_Normal_Ui();
    void _Server_Satution_For_requestCode2();
    // ---------------------

    // -------------------
    QTimer *timer = nullptr;
    bool _flag_wait_Thread = false ;

    void _checkThread();

    void _filterPlot_minAndMax_mod(QString L_bound, QString L_code, QString U_bound, QString U_code);
    // void _filterPlot_Min_mod();
    // void _filterPlot_Max_mod();

    // ---------------------



};
#endif // MAINWINDOW_H
