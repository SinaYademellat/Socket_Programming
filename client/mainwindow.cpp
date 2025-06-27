#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    guiManager.showLoginForm(this,{this->ui->Form1,this->ui->Form2,this->ui->Form3,this->ui->Form4});


    this->loginManager.SetClient(&this->MainClientIs_Global);
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////////////////////////////////////////////

void MainWindow::on_pushButton_form1_Loggin_clicked()
{
    if(this->verifyRequiredFields())
    {
        if(this->canEnterDashboard()){
            this->guiManager.showMainForm(this,
                                                 this->ui->frame_LoggingForm,{this->ui->Form1,this->ui->Form2,this->ui->Form3,this->ui->Form4},
                                                 this->chartTest1.colorsFor_colorCombo_IS,this->mybasicfunctis,
                                                 this->ui->colorCombox_1_Max,this->ui->colorCombox_2_Min,
                                                 this->ui->horizontalSlider_FPS,this->ui->label_FPSValue
                                                 );
        }
        else
        {
            qDebug()<<" canEnterDashboard() -> False :) ";
            return;
        }
    }
    else{
        qDebug()<<" verifyRequiredFields() -> False :) ";
        return ;
    }

}

bool MainWindow::verifyRequiredFields(){

    QString input_ip_is  = this->ui->IP_inForm1->text();
    QString input_port_is = this->ui->Port_inForm1->text();
    QString input_username_is = this->ui->UserName_inform1->text();
    QString input_password_is = this->ui->Passwor_inForm1->text();

    return this->loginManager.validateFormInputs(this,input_ip_is,input_port_is,input_username_is,input_password_is);
}


bool MainWindow::canEnterDashboard()
{
    int Global_code = 1;
    QStringList parr1;
    parr1 << MainClientIs_Global._userName  << MainClientIs_Global._passWord;
    this->MainClientIs_Global.handle_client_request(Global_code,parr1);

    QString colorForstatusIcon = "";
    if(this->MainClientIs_Global.Connection)
    {
        if(this->MainClientIs_Global.passwordAndUsername) {
            colorForstatusIcon = "green";
            this->ui->label_Usernname->setText(MainClientIs_Global._userName);
            QString IpandPort = QString(MainClientIs_Global._serverIP) + QString(" : ") + QString::number(MainClientIs_Global._serverPort);
            this->ui->label_IP->setText(IpandPort);
            mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
            return true;
        }
        else{
            colorForstatusIcon = "yellow";
            QMessageBox::warning(this, "اتصال به سرور", "رمز یا کلمه عبور اشتباه است");
            mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
            return false;
        }

    }
    else{
        colorForstatusIcon = "red";
        QMessageBox::warning(this, "اتصال به سرور", "سرور خاموش است");
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
        return false;
    }
    return true;
}



// =============================================

void MainWindow::updateChart()
{
    this->_Refresh_chart();
    this->_SetModeOFChart();
    if(this->MainClientIs_Global.server_anserData.size()>=1)
    {
        this->chartTest1.PlotChart(ui->chartFrame ,this->MainClientIs_Global.server_anserData );
    }
    else
    {
        qDebug()<<" List is EMTY";
        return;
    }
}

void MainWindow::_Refresh_chart()
{
    if (QLayout *layout = ui->chartFrame->layout())
    {
        QLayoutItem *item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget())
                item->widget()->deleteLater();
            delete item;
        }
    }
    else
    {
        ui->chartFrame->setLayout(new QVBoxLayout());
    }

}

void MainWindow::_SetModeOFChart()
{
    if (ui->radioBarChart->isChecked()) // Bar chart
    {
        chartTest1.mode ='B';
    }
    else
    {
        // Line chart
        chartTest1.mode ='L';
    }

}

// =============================================

void MainWindow::on_pushButton_form2_clicked()
{
    if(this->_flag_wait_Thread){
        return;
    }

    if(ui->radioMax->isChecked()){
        this->_Sampling_Maximum_Ui();
    }
    else if(ui->radioMin->isChecked()){
        this->_Sampling_Minimum_Ui();
    }
    else{
        this->_Sampling_Normal_Ui();
    }

    this->_Server_Satution_For_requestCode2();
    this->updateChart();
}

void MainWindow::_Sampling_Maximum_Ui()
{

    int Global_code = 2;
    QStringList ParametersIS;

    QString RangeNumber = ui->lineEdit_Range_form2->text();
    if (RangeNumber.isEmpty()) {
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا بازه را وراد کنید");
        this->_flag_wait_Thread = true;
        return ;
    }

    bool numIsok = false;
    int num = RangeNumber.toInt(&numIsok);
    if(numIsok)
    {
        if(100%num==0)
        {
            ParametersIS << MainClientIs_Global.token<< "Max" << RangeNumber;
            MainClientIs_Global.handle_client_request(Global_code,ParametersIS);
            // Set Text of Request in UI
            QString show_client_Request = MainClientIs_Global.token +  " Max " + RangeNumber;
            this->ui->label_MessageIS->setText(show_client_Request);
            this->_flag_wait_Thread = false;
            return;
        }
        else
        {
            QMessageBox::warning(this, "ورودی بازه" , " لطفا بازه انتخاب شده مقسوم‌علیه ۱۰۰ باشد");
            this->_flag_wait_Thread = true;
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "ورودی بازه" , " لطفا بازه انتخاب شده عدد صیح باشد");
        this->_flag_wait_Thread = true;
        return;
    }
}

void MainWindow::_Sampling_Minimum_Ui()
{
    int Global_code = 2;
    QStringList ParametersIS;

    QString RangeNumber = ui->lineEdit_Range_form2->text();
    if (RangeNumber.isEmpty()) {
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا بازه را وراد کنید");
        this->_flag_wait_Thread = true;
        return;
    }
    bool numIsok = false;
    int num = RangeNumber.toInt(&numIsok);
    if(numIsok)
    {
        if(100%num==0)
        {
            ParametersIS << MainClientIs_Global.token<< "Min" << RangeNumber;
            MainClientIs_Global.handle_client_request(Global_code,ParametersIS);
            // Set Text of Request in UI
            QString show_client_Request = MainClientIs_Global.token +  " Min " + RangeNumber;
            this->ui->label_MessageIS->setText(show_client_Request);
            this->_flag_wait_Thread = false;
            return;
        }
        else
        {
            QMessageBox::warning(this, "ورودی بازه" , " لطفا بازه انتخاب شده مقسوم‌علیه ۱۰۰ باشد");
            this->_flag_wait_Thread = true;
            return;
        }
    }
    else
    {
        QMessageBox::warning(this, "ورودی بازه" , " لطفا بازه انتخاب شده عدد صیح باشد");
        this->_flag_wait_Thread = true;
        return;
    }
}

void MainWindow::_Sampling_Normal_Ui()
{
    int Global_code = 2;
    QStringList ParametersIS;

    ParametersIS << MainClientIs_Global.token<< "Normal" <<"1";
    MainClientIs_Global.handle_client_request(Global_code,ParametersIS);

    // Set Text of Request in UI
    QString show_client_Request = MainClientIs_Global.token +  " Normal " + " 1";
    this->ui->label_MessageIS->setText(show_client_Request);
}

void MainWindow::_Server_Satution_For_requestCode2()
{
    QString colorForstatusIcon = "";
    if(this->MainClientIs_Global.Connection)
    {
        colorForstatusIcon = "green";
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form2_server ,colorForstatusIcon);

    }
    else
    {
        colorForstatusIcon = "red";
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form2_server ,colorForstatusIcon);
        this->MainClientIs_Global.server_anserData.clear();
    }
}

// =============================================

void MainWindow::on_pushButton_form3_clicked()
{
    this->_flag_wait_Thread = false;

    double fpsminput = ui->horizontalSlider_FPS->value();
    int fps = static_cast<int> (fpsminput*1000);

    this->_RefreshThread();
    connect(this->timer , &QTimer::timeout, this, [=](){
            this->on_pushButton_form2_clicked();
            if(this->MainClientIs_Global.Connection == false)
            {
                qDebug()<<"MMMMMMM";
                this->timer->stop();
                return;
            }
    });

    this->timer->start(1000);
}



void MainWindow::_RefreshThread(){
    if( (this->timer == nullptr) )
    {
        this->timer = new QTimer(this);
    }
    else
    {
        this->timer->stop();
        this->timer = new QTimer(this);
    }
}

void MainWindow::on_pushButton_form4_Filter_clicked()
{
    if( (this->timer == nullptr) )
    {
        qDebug() << "Timer is Null :)" ;
    }
    else
    {
        qDebug() << "Stop" ;
        this->timer->stop();
    }

    this->_Refresh_chart();
    this->_SetModeOFChart();

    QString code_Max_color = ui->colorCombox_1_Max->currentText();
    QString code_Min_color = ui->colorCombox_2_Min->currentText();

    QString bound_Max_color = ui->lineEdit_Max_form4->text();
    QString bound_Min_color = ui->lineEdit_Min_form4->text();

    if((ui->checkBox_Max->isChecked() ) && (ui->checkBox_Min->isChecked() ))
    {
        // Max
        bool ok1_Max;
        int threshold_Max  = bound_Max_color.toInt(&ok1_Max);
        bool ok2_Max;
        int UpCodeIs = code_Max_color.toInt(&ok2_Max);
        // Min
        bool ok1_Min;
        int threshold_Min  = bound_Min_color.toInt(&ok1_Min);
        bool ok2_Min;
        int lowCodeIs = code_Min_color.toInt(&ok2_Min);

        this->chartTest1.plotChartWithMin_and_MaxFilter(ui->chartFrame ,this->MainClientIs_Global.server_anserData ,threshold_Min,lowCodeIs,threshold_Max,UpCodeIs);
    }
    else if(ui->checkBox_Max->isChecked()){
        // Max
        bool ok1;
        int threshold  = bound_Max_color.toInt(&ok1);

        bool ok2;
        int UpCodeIs = code_Max_color.toInt(&ok2);

        this->chartTest1.plotChartWithMaxFilter(ui->chartFrame ,this->MainClientIs_Global.server_anserData ,  threshold  ,UpCodeIs );
    }
    else if(ui->checkBox_Min->isChecked()){
        // Min
        bool ok1;
        int threshold  = bound_Min_color.toInt(&ok1);

        bool ok2;
        int lowCodeIs = code_Min_color.toInt(&ok2);

        this->chartTest1.plotChartWithMinFilter(ui->chartFrame ,this->MainClientIs_Global.server_anserData ,  threshold  ,lowCodeIs );
    }
    else{
        this->updateChart();
        qDebug()<<"No check Box";
    }
}

void MainWindow::on_pushButton_form4_Clean_clicked()
{
    this->updateChart();

}

