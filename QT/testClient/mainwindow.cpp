#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

#include <QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Form_2->setEnabled(false);
    ui->Form_3->setEnabled(false);
    ui->Form_4->setEnabled(false);


    ui->doubleSpinBox->setMinimum(0.0);
    ui->doubleSpinBox->setMaximum(1.0);
    ui->doubleSpinBox->setSingleStep(0.1);
    ui->doubleSpinBox->setDecimals(2);


    // ************************************

    QChart *chart = new QChart();
    QBarSet *set0 = new QBarSet("نمودار طیف");
    for (int i =0 ; i<100 ; i++)
    {
        *set0<<0;
    }

    QBarSeries *series = new QBarSeries();
    series->append(set0);
    chart->addSeries(series);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *layout = new QVBoxLayout(ui->chartContainer);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(chartView);

    // **********************

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::newChart()
{
    if (chartView) {
        delete chartView;
        chartView = nullptr;
    }

    QBarSet *set = new QBarSet("جدید");

    for (int i =0 ; i < MainClientIs_Global.server_anserData.size() ; i++)
    {
        *set <<MainClientIs_Global.server_anserData[i];
    }


    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *newChart = new QChart();
    newChart->addSeries(series);


    QValueAxis *axisY = new QValueAxis();
    newChart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chartView = new QChartView(newChart);
    chartView->setRenderHint(QPainter::Antialiasing);

    auto layout = qobject_cast<QVBoxLayout *>(ui->chartContainer->layout());
    if (layout)
        layout->addWidget(chartView);
}


void MainWindow::RunRequestFps(double  fpsminput)
{
    int fps = static_cast<int> (fpsminput*1000);

    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, [=]() {

        if(ui->RB_normal->isChecked())
        {
            int Global_code = 2;
            QStringList parrs;
            parrs << MainClientIs_Global.uniqCode<< "Normal" <<"1";
            MainClientIs_Global.handle_client_request(Global_code,parrs);
            // return;
        }
        else
        {
            QString RangeNumber = ui->Rang_form2->text();
            if (RangeNumber.isEmpty()) {
                RangeNumber = "100";
                return;
            }

            int Global_code = 2;
            QStringList parrs;

            if(ui->RB_Max->isChecked())
            {
                parrs << MainClientIs_Global.uniqCode<< "Max" << RangeNumber;
                qDebug()<<parrs[0] << parrs[1];
                MainClientIs_Global.handle_client_request(Global_code,parrs);
                // return;
            }
            else
            {
                parrs << MainClientIs_Global.uniqCode<< "Min" << RangeNumber;
                qDebug()<<parrs[0] << parrs[1];
                MainClientIs_Global.handle_client_request(Global_code,parrs);
                // return;
            }
        }
        this->newChart();
        counter_time++;
        qDebug() << "time:" << counter_time;
    });

    timer->start(fps);
}


void MainWindow::on_BT_form1_clicked()
{
    qDebug()<<"*****************";
    QString ip = ui->IP_inForm1->text();
    if (ip.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفا یک آدرس IP وارد کنید.");
        return;
    }
    qDebug() << "IP is:" << ip;

    qDebug()<<"*****************";
    QString port = ui->Port_inForm1->text();
    if (port.isEmpty()) {
        QMessageBox::warning(this, "خطا", "لطفا یک آدرس port وارد کنید.");
        return;
    }
    qDebug() << "port is:" << port;

    qDebug()<<"*****************";
    QString username = ui->UserName_inform1->text();
    if (username.isEmpty()) {
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا نام کاربری را وراد کنید");
        return;
    }
    qDebug() << "username is:" << username;

    qDebug()<<"*****************";
    QString Password = ui->Passwor_inForm1->text();
    if (Password.isEmpty()) {
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا رمز را وراد کنید");
        return;
    }
    qDebug() << "Password is:" << Password;
    qDebug()<<"*****************";
    //  =============================
    bool ok;
    quint16 valuePort = port.toUShort(&ok);  // toUnsignedShort
    if (ok) {
        qDebug() << "NewPort: " << valuePort;
    } else {
        qDebug() << "Error";
    }

    // ClientClassTcp testClient(ip ,valuePort);
// ------------------
    MainClientIs_Global._serverIP =ip;
    MainClientIs_Global._serverPort = valuePort;
// ------------------
    int Global_code = 1;
    QStringList parr1;
    parr1 << username <<Password;
    MainClientIs_Global.handle_client_request(Global_code,parr1);

    if(MainClientIs_Global.Connection == true)
    {
        MainClientIs_Global.Connection = false;

        if(MainClientIs_Global.passwordAndUsername == true)
        {
            ui->statusIcon_form1->setStyleSheet(
                "QLabel {"
                "background-color: green;"
                "border-radius: 10px;"
                "border: 1px solid black;""}");
        }
        else
        {
            ui->statusIcon_form1->setStyleSheet(
                "QLabel {"
                "background-color: yellow;"
                "border-radius: 10px;"
                "border: 1px solid black;""}");
        }

    }
    else
    {
                ui->statusIcon_form1->setStyleSheet(
                    "QLabel {"
                    "background-color: red;"
                    "border-radius: 10px;"
                    "border: 1px solid black;""}");

    }

// -------------------
    ui->Form_2->setEnabled(true);
    ui->Form_3->setEnabled(true);
    ui->Form_4->setEnabled(true);

}

void MainWindow::on_BT_form2_clicked()
{
    if(ui->RB_normal->isChecked())
    {
        int Global_code = 2;
        QStringList parrs;
        parrs << MainClientIs_Global.uniqCode<< "Normal" <<"1";
        MainClientIs_Global.handle_client_request(Global_code,parrs);
        // return;
    }
    else
    {
        QString RangeNumber = ui->Rang_form2->text();
        if (RangeNumber.isEmpty()) {
            QMessageBox::warning(this, "خالی بودن فایل" , " لطفا بازه را وراد کنید");
            return;
        }

        int Global_code = 2;
        QStringList parrs;

        if(ui->RB_Max->isChecked())
        {
            parrs << MainClientIs_Global.uniqCode<< "Max" << RangeNumber;
            qDebug()<<parrs[0] << parrs[1];
            MainClientIs_Global.handle_client_request(Global_code,parrs);
            // return;
        }
        else
        {
            parrs << MainClientIs_Global.uniqCode<< "Min" << RangeNumber;
            qDebug()<<parrs[0] << parrs[1];
            MainClientIs_Global.handle_client_request(Global_code,parrs);
            // return;
        }
    }
    this->newChart();

//////////////////////////////// plot


}

void MainWindow::on_BT_form3_clicked()
{
    double val = ui->doubleSpinBox->value();
    this->RunRequestFps(val);
}
