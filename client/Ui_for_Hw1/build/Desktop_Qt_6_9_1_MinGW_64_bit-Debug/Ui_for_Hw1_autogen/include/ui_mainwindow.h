/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *Form3;
    QPushButton *pushButton_form3;
    QLabel *statusIcon_form3;
    QLabel *label_FPSValue;
    QLabel *label_7;
    QSlider *horizontalSlider_FPS;
    QLabel *label_LineICON;
    QLabel *label_BarIcon;
    QRadioButton *radiolineChart;
    QRadioButton *radioBarChart;
    QFrame *Form4;
    QCheckBox *checkBox_Max;
    QLineEdit *lineEdit_Min_form4;
    QLineEdit *lineEdit_Max_form4;
    QComboBox *colorCombox_2_Min;
    QComboBox *colorCombox_1_Max;
    QCheckBox *checkBox_Min;
    QPushButton *pushButton_form4_Filter;
    QPushButton *pushButton_form4_Clean;
    QLabel *statusIcon_form1_2;
    QFrame *Form2;
    QRadioButton *radioNormal;
    QRadioButton *radioMin;
    QLineEdit *lineEdit_Range_form2;
    QLabel *statusIcon_form2_server;
    QRadioButton *radioMax;
    QPushButton *pushButton_form2;
    QFrame *Form1;
    QLabel *statusIcon_form1_server;
    QLabel *label_UserName_Blue;
    QLabel *label_Usernname;
    QLabel *label_IP;
    QLabel *label_20;
    QLabel *label_MessageIS;
    QFrame *chartFrame;
    QFrame *frame_LoggingForm;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *UserName_inform1;
    QLineEdit *Port_inForm1;
    QLineEdit *IP_inForm1;
    QLabel *label;
    QPushButton *pushButton_form1_Loggin;
    QLabel *label_UserName_Blue_2;
    QLineEdit *Passwor_inForm1;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1389, 605);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: #2E2E2E;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Form3 = new QFrame(centralwidget);
        Form3->setObjectName("Form3");
        Form3->setGeometry(QRect(500, 10, 251, 121));
        Form3->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00CFFF;\n"
"    background-color: transparent;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}"));
        Form3->setFrameShape(QFrame::Shape::StyledPanel);
        Form3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_form3 = new QPushButton(Form3);
        pushButton_form3->setObjectName("pushButton_form3");
        pushButton_form3->setGeometry(QRect(10, 80, 201, 31));
        pushButton_form3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #00CFFF;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #16A085;\n"
"    border: 1px solid #16A085;\n"
"}\n"
""));
        statusIcon_form3 = new QLabel(Form3);
        statusIcon_form3->setObjectName("statusIcon_form3");
        statusIcon_form3->setGeometry(QRect(220, 90, 22, 22));
        statusIcon_form3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white ;\n"
"    border-radius: 10px;\n"
"    border: 1px solid black;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"    max-width: 20px;\n"
"    max-height: 20px;\n"
"}\n"
""));
        label_FPSValue = new QLabel(Form3);
        label_FPSValue->setObjectName("label_FPSValue");
        label_FPSValue->setGeometry(QRect(160, 20, 41, 31));
        label_FPSValue->setStyleSheet(QString::fromUtf8("color: #00AAFF;\n"
"font-size: 18px;\n"
"height: 6px;\n"
"\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"  "));
        label_7 = new QLabel(Form3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(120, 20, 41, 31));
        label_7->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #00CFFF;\n"
"background-color: transparent;\n"
""));
        horizontalSlider_FPS = new QSlider(Form3);
        horizontalSlider_FPS->setObjectName("horizontalSlider_FPS");
        horizontalSlider_FPS->setGeometry(QRect(100, 50, 137, 18));
        horizontalSlider_FPS->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"    border: 1px solid #444;\n"
"    height: 6px;\n"
"    background: #2a2a2a;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"    background: #00CFFF;\n"
"    border: none;\n"
"    width: 14px;\n"
"    height: 14px;\n"
"    margin: -4px 0;\n"
"    border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: #00CFFF;\n"
"    border-radius: 3px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"    background: #444;\n"
"    border-radius: 3px;\n"
"}\n"
""));
        horizontalSlider_FPS->setOrientation(Qt::Orientation::Horizontal);
        label_LineICON = new QLabel(Form3);
        label_LineICON->setObjectName("label_LineICON");
        label_LineICON->setGeometry(QRect(40, 10, 31, 31));
        label_LineICON->setPixmap(QPixmap(QString::fromUtf8("C:/Users/sina/Downloads/icons8-line-chart-64 (1).png")));
        label_LineICON->setScaledContents(true);
        label_BarIcon = new QLabel(Form3);
        label_BarIcon->setObjectName("label_BarIcon");
        label_BarIcon->setGeometry(QRect(40, 40, 31, 31));
        label_BarIcon->setPixmap(QPixmap(QString::fromUtf8("C:/Users/sina/Downloads/icons8-bar-chart-48.png")));
        label_BarIcon->setScaledContents(true);
        radiolineChart = new QRadioButton(Form3);
        radiolineChart->setObjectName("radiolineChart");
        radiolineChart->setGeometry(QRect(10, 20, 20, 20));
        radiolineChart->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: BLACK;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #1ABC9C;    \n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1ABC9C; \n"
"    border: 2px solid #16A085;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"}\n"
""));
        radioBarChart = new QRadioButton(Form3);
        radioBarChart->setObjectName("radioBarChart");
        radioBarChart->setGeometry(QRect(10, 50, 20, 20));
        radioBarChart->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
"    color: BLACK;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #1ABC9C;    \n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1ABC9C; \n"
"    border: 2px solid #16A085;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"}\n"
""));
        Form4 = new QFrame(centralwidget);
        Form4->setObjectName("Form4");
        Form4->setGeometry(QRect(750, 10, 281, 121));
        Form4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00CFFF;\n"
"    background-color: transparent;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}"));
        Form4->setFrameShape(QFrame::Shape::StyledPanel);
        Form4->setFrameShadow(QFrame::Shadow::Raised);
        checkBox_Max = new QCheckBox(Form4);
        checkBox_Max->setObjectName("checkBox_Max");
        checkBox_Max->setGeometry(QRect(12, 16, 21, 20));
        checkBox_Max->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    color: #00CFFF;\n"
"    spacing: 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 4px;\n"
"    border: 2px solid #00CFFF;\n"
"    background-color: #2a2a2a;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: none;\n"
"    background-color: #00CFFF;\n"
"    border: 2px solid #00AACC;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"    background-color: #2a2a2a;\n"
"}\n"
""));
        lineEdit_Min_form4 = new QLineEdit(Form4);
        lineEdit_Min_form4->setObjectName("lineEdit_Min_form4");
        lineEdit_Min_form4->setGeometry(QRect(47, 47, 130, 28));
        lineEdit_Min_form4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        lineEdit_Max_form4 = new QLineEdit(Form4);
        lineEdit_Max_form4->setObjectName("lineEdit_Max_form4");
        lineEdit_Max_form4->setGeometry(QRect(47, 12, 130, 28));
        lineEdit_Max_form4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        lineEdit_Max_form4->setCursorMoveStyle(Qt::CursorMoveStyle::VisualMoveStyle);
        lineEdit_Max_form4->setClearButtonEnabled(false);
        colorCombox_2_Min = new QComboBox(Form4);
        colorCombox_2_Min->setObjectName("colorCombox_2_Min");
        colorCombox_2_Min->setGeometry(QRect(184, 47, 85, 28));
        colorCombox_2_Min->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e1e1e;\n"
"    border: 3px solid #00CFFF;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"    color: #00CFFF;\n"
"    outline: 0;\n"
"}"));
        colorCombox_1_Max = new QComboBox(Form4);
        colorCombox_1_Max->setObjectName("colorCombox_1_Max");
        colorCombox_1_Max->setGeometry(QRect(184, 12, 85, 28));
        colorCombox_1_Max->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 4px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"}\n"
"QComboBox:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"    color: #00CFFF;\n"
"    outline: 0;\n"
"}"));
        checkBox_Min = new QCheckBox(Form4);
        checkBox_Min->setObjectName("checkBox_Min");
        checkBox_Min->setGeometry(QRect(12, 51, 21, 20));
        checkBox_Min->setStyleSheet(QString::fromUtf8("QCheckBox {\n"
"    color: #00CFFF;\n"
"    spacing: 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 4px;\n"
"    border: 2px solid #00CFFF;\n"
"    background-color: #2a2a2a;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    image: none;\n"
"    background-color: #00CFFF;\n"
"    border: 2px solid #00AACC;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"    background-color: #2a2a2a;\n"
"}\n"
""));
        pushButton_form4_Filter = new QPushButton(Form4);
        pushButton_form4_Filter->setObjectName("pushButton_form4_Filter");
        pushButton_form4_Filter->setGeometry(QRect(47, 82, 130, 27));
        pushButton_form4_Filter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #00CFFF;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #16A085;\n"
"    border: 1px solid #16A085;\n"
"}\n"
""));
        pushButton_form4_Clean = new QPushButton(Form4);
        pushButton_form4_Clean->setObjectName("pushButton_form4_Clean");
        pushButton_form4_Clean->setGeometry(QRect(184, 82, 85, 27));
        pushButton_form4_Clean->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #00CFFF;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #16A085;\n"
"    border: 1px solid #16A085;\n"
"}\n"
""));
        statusIcon_form1_2 = new QLabel(Form4);
        statusIcon_form1_2->setObjectName("statusIcon_form1_2");
        statusIcon_form1_2->setGeometry(QRect(10, 90, 22, 22));
        statusIcon_form1_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white ;\n"
"    border-radius: 10px;\n"
"    border: 1px solid black;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"    max-width: 20px;\n"
"    max-height: 20px;\n"
"}\n"
""));
        Form2 = new QFrame(centralwidget);
        Form2->setObjectName("Form2");
        Form2->setGeometry(QRect(270, 10, 229, 121));
        Form2->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00CFFF;\n"
"    background-color: transparent;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}"));
        Form2->setFrameShape(QFrame::Shape::StyledPanel);
        Form2->setFrameShadow(QFrame::Shadow::Raised);
        radioNormal = new QRadioButton(Form2);
        radioNormal->setObjectName("radioNormal");
        radioNormal->setGeometry(QRect(143, 23, 74, 20));
        radioNormal->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
" 	color: #00CFFF;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"   spacing: 8px;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #1ABC9C;    \n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1ABC9C; \n"
"    border: 2px solid #16A085;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"}\n"
""));
        radioMin = new QRadioButton(Form2);
        radioMin->setObjectName("radioMin");
        radioMin->setGeometry(QRect(78, 23, 53, 20));
        radioMin->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
" 	color: #00CFFF;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"   spacing: 8px;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #1ABC9C;    \n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1ABC9C; \n"
"    border: 2px solid #16A085;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"}\n"
""));
        lineEdit_Range_form2 = new QLineEdit(Form2);
        lineEdit_Range_form2->setObjectName("lineEdit_Range_form2");
        lineEdit_Range_form2->setGeometry(QRect(10, 80, 124, 35));
        lineEdit_Range_form2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        statusIcon_form2_server = new QLabel(Form2);
        statusIcon_form2_server->setObjectName("statusIcon_form2_server");
        statusIcon_form2_server->setGeometry(QRect(190, 90, 22, 22));
        statusIcon_form2_server->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white ;\n"
"    border-radius: 10px;\n"
"    border: 1px solid black;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"    max-width: 20px;\n"
"    max-height: 20px;\n"
"}\n"
""));
        radioMax = new QRadioButton(Form2);
        radioMax->setObjectName("radioMax");
        radioMax->setGeometry(QRect(12, 23, 55, 20));
        radioMax->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
" 	color: #00CFFF;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"   spacing: 8px;\n"
"}\n"
"QRadioButton::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"    border-radius: 8px;\n"
"    border: 2px solid #1ABC9C;    \n"
"    background-color: #2C3E50;\n"
"}\n"
"\n"
"QRadioButton::indicator:checked {\n"
"    background-color: #1ABC9C; \n"
"    border: 2px solid #16A085;\n"
"}\n"
"\n"
"QRadioButton::indicator:unchecked:hover {\n"
"    border: 2px solid #F39C12;\n"
"}\n"
""));
        pushButton_form2 = new QPushButton(Form2);
        pushButton_form2->setObjectName("pushButton_form2");
        pushButton_form2->setGeometry(QRect(140, 80, 41, 31));
        pushButton_form2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #00CFFF;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #16A085;\n"
"    border: 1px solid #16A085;\n"
"}\n"
""));
        Form1 = new QFrame(centralwidget);
        Form1->setObjectName("Form1");
        Form1->setGeometry(QRect(10, 10, 261, 121));
        Form1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00CFFF;\n"
"    background-color: transparent;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}"));
        Form1->setFrameShape(QFrame::Shape::StyledPanel);
        Form1->setFrameShadow(QFrame::Shadow::Raised);
        statusIcon_form1_server = new QLabel(Form1);
        statusIcon_form1_server->setObjectName("statusIcon_form1_server");
        statusIcon_form1_server->setGeometry(QRect(227, 90, 22, 22));
        statusIcon_form1_server->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: white ;\n"
"    border-radius: 10px;\n"
"    border: 1px solid black;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"    max-width: 20px;\n"
"    max-height: 20px;\n"
"}\n"
""));
        label_UserName_Blue = new QLabel(Form1);
        label_UserName_Blue->setObjectName("label_UserName_Blue");
        label_UserName_Blue->setGeometry(QRect(12, 12, 101, 19));
        label_UserName_Blue->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #00CFFF;\n"
"background-color: transparent;\n"
""));
        label_Usernname = new QLabel(Form1);
        label_Usernname->setObjectName("label_Usernname");
        label_Usernname->setGeometry(QRect(120, 12, 129, 19));
        label_Usernname->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #80D8C3;\n"
"background-color: transparent;\n"
""));
        label_IP = new QLabel(Form1);
        label_IP->setObjectName("label_IP");
        label_IP->setGeometry(QRect(12, 38, 241, 19));
        label_IP->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #16A085;\n"
"background-color: transparent;\n"
""));
        label_20 = new QLabel(Form1);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(12, 64, 31, 19));
        label_20->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #00CFFF;\n"
"background-color: transparent;\n"
""));
        label_MessageIS = new QLabel(Form1);
        label_MessageIS->setObjectName("label_MessageIS");
        label_MessageIS->setGeometry(QRect(46, 64, 211, 20));
        label_MessageIS->setStyleSheet(QString::fromUtf8("\n"
"font-size: 17px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"color: rgb(255, 214, 107);\n"
"background-color: transparent;\n"
""));
        chartFrame = new QFrame(centralwidget);
        chartFrame->setObjectName("chartFrame");
        chartFrame->setGeometry(QRect(10, 140, 1371, 431));
        chartFrame->setFrameShape(QFrame::Shape::StyledPanel);
        chartFrame->setFrameShadow(QFrame::Shadow::Raised);
        frame_LoggingForm = new QFrame(centralwidget);
        frame_LoggingForm->setObjectName("frame_LoggingForm");
        frame_LoggingForm->setGeometry(QRect(30, 120, 341, 341));
        frame_LoggingForm->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    background-color: #1e1e1e;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #00CFFF;\n"
"    background-color: transparent;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 14px;\n"
"    border: none;\n"
"}"));
        frame_LoggingForm->setFrameShape(QFrame::Shape::StyledPanel);
        frame_LoggingForm->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame_LoggingForm);
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(frame_LoggingForm);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: #F1C40F;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 2px 2px;\n"
"border-radius: 5px;\n"
""));

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        UserName_inform1 = new QLineEdit(frame_LoggingForm);
        UserName_inform1->setObjectName("UserName_inform1");
        UserName_inform1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 20px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));

        gridLayout->addWidget(UserName_inform1, 4, 0, 1, 2);

        Port_inForm1 = new QLineEdit(frame_LoggingForm);
        Port_inForm1->setObjectName("Port_inForm1");
        Port_inForm1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 20px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));

        gridLayout->addWidget(Port_inForm1, 3, 1, 1, 1);

        IP_inForm1 = new QLineEdit(frame_LoggingForm);
        IP_inForm1->setObjectName("IP_inForm1");
        IP_inForm1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 20px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));

        gridLayout->addWidget(IP_inForm1, 2, 1, 1, 1);

        label = new QLabel(frame_LoggingForm);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("color: #F1C40F;\n"
"font-size: 20px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        pushButton_form1_Loggin = new QPushButton(frame_LoggingForm);
        pushButton_form1_Loggin->setObjectName("pushButton_form1_Loggin");
        pushButton_form1_Loggin->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pushButton_form1_Loggin->setMouseTracking(true);
        pushButton_form1_Loggin->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        pushButton_form1_Loggin->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #00CFFF;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #1ABC9C;\n"
"    color: black;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #16A085;\n"
"    border: 1px solid #16A085;\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_form1_Loggin, 6, 0, 1, 2);

        label_UserName_Blue_2 = new QLabel(frame_LoggingForm);
        label_UserName_Blue_2->setObjectName("label_UserName_Blue_2");
        label_UserName_Blue_2->setStyleSheet(QString::fromUtf8("\n"
"font-size: 28px;;\n"
"height: 6px;\n"
"margin: 0px;\n"
"border-radius: 3px;\n"
"\n"
"color: #F1C40F;\n"
"background-color: transparent;\n"
""));

        gridLayout->addWidget(label_UserName_Blue_2, 1, 0, 1, 2);

        Passwor_inForm1 = new QLineEdit(frame_LoggingForm);
        Passwor_inForm1->setObjectName("Passwor_inForm1");
        Passwor_inForm1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #2a2a2a;\n"
"    color: #00CFFF;\n"
"    border: 1px solid #00CFFF;\n"
"    border-radius: 6px;\n"
"    padding: 6px 8px;\n"
"    font-family: 'Segoe UI';\n"
"    font-size: 20px;\n"
"    selection-background-color: #00CFFF;\n"
"    selection-color: #1e1e1e;\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 1px solid #F39C12;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1px solid #1ABC9C;\n"
"    background-color: #1e1e1e;\n"
"}\n"
""));
        Passwor_inForm1->setEchoMode(QLineEdit::EchoMode::Password);

        gridLayout->addWidget(Passwor_inForm1, 5, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1389, 25));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_form3->setText(QCoreApplication::translate("MainWindow", "Ok", nullptr));
        statusIcon_form3->setText(QString());
        label_FPSValue->setText(QCoreApplication::translate("MainWindow", "1.00", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "FPS :", nullptr));
        label_LineICON->setText(QString());
        label_BarIcon->setText(QString());
        radiolineChart->setText(QString());
        radioBarChart->setText(QString());
        checkBox_Max->setText(QString());
        lineEdit_Min_form4->setPlaceholderText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        lineEdit_Max_form4->setPlaceholderText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        checkBox_Min->setText(QString());
        pushButton_form4_Filter->setText(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        pushButton_form4_Clean->setText(QCoreApplication::translate("MainWindow", "clean", nullptr));
        statusIcon_form1_2->setText(QString());
        radioNormal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        radioMin->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        lineEdit_Range_form2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Range", nullptr));
        statusIcon_form2_server->setText(QString());
        radioMax->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        pushButton_form2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        statusIcon_form1_server->setText(QString());
        label_UserName_Blue->setText(QCoreApplication::translate("MainWindow", "User Name: ", nullptr));
        label_Usernname->setText(QString());
        label_IP->setText(QString());
        label_20->setText(QCoreApplication::translate("MainWindow", ">> ", nullptr));
        label_MessageIS->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "port", nullptr));
        UserName_inform1->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        Port_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        IP_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "127.0.0.2", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        pushButton_form1_Loggin->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        label_UserName_Blue_2->setText(QCoreApplication::translate("MainWindow", "      Logging form", nullptr));
        Passwor_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
