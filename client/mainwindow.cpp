#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->creatLoggingPageGui();
    // ++++++++++++++++++++++
    this->creat_GUi_Form3and4();
    // ----------------------
}

MainWindow::~MainWindow()
{
    delete ui;
}


/////////////////////// << GUI >>

/// \brief MainWindow::creat_GUi_Form3and4
void MainWindow::creat_GUi_Form3and4(){

    QList<QColor>  colorsFor_colorCombo = this->chartTest1.colorsFor_colorCombo_IS;

    mybasicfunctis.AddColorItemToQcomBox(ui->colorCombox_1_Max , colorsFor_colorCombo);
    mybasicfunctis.AddColorItemToQcomBox(ui->colorCombox_2_Min , colorsFor_colorCombo);
    // ++++++++++++++++++++++
    // ------------
    mybasicfunctis.SetGuiBlineBar(ui->horizontalSlider_FPS,1,100,1,100);
    connect(ui->horizontalSlider_FPS, &QSlider::valueChanged, this, [=](int value){
        double decimalValue = value / 100.0;
        ui->label_FPSValue->setText(QString::number(decimalValue, 'f', 2));
    });
}

void MainWindow::creatLoggingPageGui(){
    this->ui->Form1->hide();
    this->ui->Form2->hide();
    this->ui->Form3->hide();
    this->ui->Form4->hide();
    this->setGeometry(20,30,419,551);
    // ui->frame_LoggingForm->show();
}

void MainWindow::creat_main_Form_Gui(){
    // this->resize(1027, 551);
    this->resize(1389, 605);

    ui->Form1->show();
    ui->Form2->show();
    ui->Form3->show();
    ui->Form4->show();
    ui->frame_LoggingForm->hide();
}



////////////////////////////////////////////////
/// \brief MainWindow::on_pushButton_form1_Loggin_clicked
/// ~~~~~~~~~~~~~~~~~~~~~~
///  برسی فرم شماره یک : احراز هویت
/// ~~~~~~~~~~~~~~~~~~~~~~

void MainWindow::on_pushButton_form1_Loggin_clicked()
{
    qDebug()<<" ******************** ";
    if(this->_checkForms())
    {
        if(this->_canUseDasBord()){
            this->creat_main_Form_Gui();
        }
        else
        {
            QMessageBox::warning(this, "اتصال به سرور" ,"دوباره تلاش کنید");
            return;
        }
    }
    else{
        return ;
    }

}

bool MainWindow::_checkForms(){
    // -----------
    if(this->_check_Ip_Gui()){
        qDebug() << "IP is   :" << this->MainClientIs_Global._serverIP;
    }
    else{
        QMessageBox::warning(this, "خطا", "لطفا یک آدرس IP وارد کنید.");
        return false ;
    }
    // -----------
    if(this->_check_Port_Gui()){
        qDebug() << "Port is:" << MainClientIs_Global._serverPort;
    }
    else{
        return false;
    }
    // -----------
    if(this->_check_Username_Gui()){
        qDebug() << "username is:" << MainClientIs_Global._userName;
    }
    else{
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا نام کاربری را وراد کنید");
        return false;
    }
    // -----------
    if(this->_check_Password_Gui()){
        qDebug() << "Password is:" << MainClientIs_Global._passWord;
    }
    else{
        QMessageBox::warning(this, "خالی بودن فایل" , " لطفا رمز را وراد کنید");
        return false;
    }
    // -----------

    return true;
}


bool MainWindow::_canUseDasBord()
{

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>
    int Global_code = 1;
    QStringList parr1;
    parr1 << MainClientIs_Global._userName  << MainClientIs_Global._passWord;
    this->MainClientIs_Global.handle_client_request(Global_code,parr1);

    QString colorForstatusIcon = "";
    if(this->MainClientIs_Global.Connection)
    {
        if(this->MainClientIs_Global.passwordAndUsername)
        {
            colorForstatusIcon = "green";
            this->ui->label_Usernname->setText("Sina");
            QString IpandPort = QString(MainClientIs_Global._serverIP) + QString(" : ") + QString::number(MainClientIs_Global._serverPort);
            // qDebug()<<" << IpandPort >> "<< IpandPort ;
            this->ui->label_IP->setText(IpandPort);
            mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
            return true;
        }
        else
        {
            colorForstatusIcon = "yellow";
            QMessageBox::warning(this, "اتصال به سرور", "رمز یا کلمه عبور اشتباه است");
            mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
            return false;
        }

    }
    else
    {

        colorForstatusIcon = "red";
        QMessageBox::warning(this, "اتصال به سرور", "سرور خاموش است");
        mybasicfunctis.setServerStatusColor(ui->statusIcon_form1_server ,colorForstatusIcon);
        return false;
    }
    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>
    return true;
}


bool MainWindow::_check_Ip_Gui(){
    QString ip = this->ui->IP_inForm1->text();
    if (ip.isEmpty()) {
        return false;
    }
    else{
        this->MainClientIs_Global._serverIP = ip;
        return true;
    }
}

bool MainWindow::_check_Port_Gui(){
    QString port = this->ui->Port_inForm1->text();
    if (port.isEmpty()) {
        QMessageBox::warning(this, "مقدار پورت", "پورت خالی هست");
        return false;
    }
    else{
        //  =============================
        bool ok;
        quint16 valuePort = port.toUShort(&ok);  // toUnsignedShort
        if (ok) {
            this->MainClientIs_Global._serverPort = valuePort;
            return true;
        }
        else {
            QMessageBox::warning(this, "مقدار پورت", "لطفا برای پورت یک عدد  صیح مثبت باشد");
            return false;
        }
        //  =============================

    }
}

bool MainWindow::_check_Username_Gui(){
    QString username = this->ui->UserName_inform1->text();
    if (username.isEmpty()) {
        return false;
    }
    else{
        this->MainClientIs_Global._userName = username;
        return true;
    }
}

bool MainWindow::_check_Password_Gui(){
    QString Password = ui->Passwor_inForm1->text();
    if (Password.isEmpty()) {
        return false;
    }
    else{
        this->MainClientIs_Global._passWord = Password;
        return true;
    }
}



///=============================================


////////////////////////////////////////////////
/// \brief MainWindow::updateChart
///  امکان بروزرسانی جدول
/// با حذف کردن داده های قبلی و
///  تشخیص نوع جدول و
/// و در نهایت جدول را بروز رسانی کردیم

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
    else // ui->radiolineChart->isChecked() Defult
    {
        // Line chart
        chartTest1.mode ='L';
    }

}

///=============================================


////////////////////////////////////////////////
/// \brief MainWindow::on_pushButton_form2_clicked
/// ~~~~~~~~~~~~~~~~~~~~~~
///  برسی فرم شماره دو : امکان ارسال یک سطر از داده ها
/// ~~~~~~~~~~~~~~~~~~~~~~

void MainWindow::on_pushButton_form2_clicked()
{
    if(this->_flag_wait_Thread){
        return;
    }


    if(ui->radioMax->isChecked())
    {
        this->_Sampling_Maximum_Ui();
    }
    else if(ui->radioMin->isChecked())
    {
        this->_Sampling_Minimum_Ui();
    }
    else
    {
        this->_Sampling_Normal_Ui();
    }

    // رنگ علامت سرور
    this->_Server_Satution_For_requestCode2();
    // نمایش دیتا
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

    ///
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

///=============================================




////////////////////////////////////////////////
/// \brief MainWindow::on_pushButton_form3_clicked
// ~~~~~~~~~~~~~~~~~~~~~~
//  برسی فرم شماره سه
// ~~~~~~~~~~~~~~~~~~~~~~

void MainWindow::on_pushButton_form3_clicked()
{
    this->_flag_wait_Thread = false;

    double fpsminput = ui->horizontalSlider_FPS->value();
    int fps = static_cast<int> (fpsminput*1000);

    this->_checkThread();
    connect(this->timer , &QTimer::timeout, this, [=](){

            // qDebug()<<"hi";
            // this->update();
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



void MainWindow::_checkThread(){
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



void MainWindow::_filterPlot_minAndMax_mod(QString L_bound, QString L_code, QString U_bound, QString U_code)
{
    if(this->MainClientIs_Global.server_anserData.size()>=1)
    {
        // low
        bool canConvertToint_L_code;
        int lowCodeIs = L_code.toInt(&canConvertToint_L_code);
        bool canConvertToint_L_bound;
        int Low_boundIS = L_bound.toInt(&canConvertToint_L_bound);

        // Up
        bool canConvertToint_U_Code;
        int UpCodeIS = U_code.toInt(&canConvertToint_U_Code);
        bool canConvertToint_U_bound;
        int Up_boundIS = U_bound.toInt(&canConvertToint_U_bound);

        // Run
        this->chartTest1.plotChartWithMin_and_MaxFilter(ui->chartFrame ,this->MainClientIs_Global.server_anserData , Low_boundIS ,lowCodeIs , Up_boundIS , UpCodeIS );
    }
    else
    {
        qDebug()<<" List is EMTY";
        return;
    }
}

void MainWindow::on_pushButton_form4_Filter_clicked()
{

    // return;

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

    // if(ui->checkBox_Min->isChecked()){
    //     bool ok1;
    //     int valuInt = bound_Min_color.toInt(&ok1);
    //     bool ok2;
    //     int lowCodeIs = code_Min_color.toInt(&ok2);
    //     this->chartTest1.plotChartWithMinFilter(ui->chartFrame ,this->MainClientIs_Global.server_anserData ,  valuInt ,lowCodeIs );
    // }

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



