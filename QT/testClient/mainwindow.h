#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QChartView>
#include "clientclass.h"
#include <QTimer>

// extern ClientClassTcp MainClientIs_Global;

extern ClientClassTcp MainClientIs_Global;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_BT_form1_clicked();
    void on_BT_form2_clicked();

    void on_BT_form3_clicked();

private:
    Ui::MainWindow *ui;
    QChartView *chartView = nullptr;
    void newChart();
    void RunRequestFps(double  fpsminput);

    QString ip_main;
    quint16 valuePort_main;

    QTimer *timer;
    int counter_time = 0;
};
#endif // MAINWINDOW_H
