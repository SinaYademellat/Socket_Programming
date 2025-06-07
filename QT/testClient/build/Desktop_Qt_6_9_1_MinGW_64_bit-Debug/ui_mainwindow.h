/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *Form1;
    QLineEdit *IP_inForm1;
    QLabel *label;
    QLineEdit *Port_inForm1;
    QLabel *label_2;
    QLineEdit *UserName_inform1;
    QLineEdit *Passwor_inForm1;
    QPushButton *BT_form1;
    QLabel *statusIcon_form1;
    QGroupBox *Form_2;
    QGroupBox *groupBox;
    QRadioButton *RB_Max;
    QRadioButton *RB_min;
    QRadioButton *RB_normal;
    QLineEdit *Rang_form2;
    QPushButton *BT_form2;
    QGroupBox *Form_3;
    QGroupBox *groupBox_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QPushButton *BT_form3;
    QDoubleSpinBox *doubleSpinBox;
    QGroupBox *Form_4;
    QPushButton *pushButton_4;
    QFrame *chartContainer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(927, 677);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Form1 = new QGroupBox(centralwidget);
        Form1->setObjectName("Form1");
        Form1->setGeometry(QRect(20, 10, 261, 251));
        IP_inForm1 = new QLineEdit(Form1);
        IP_inForm1->setObjectName("IP_inForm1");
        IP_inForm1->setGeometry(QRect(70, 40, 161, 31));
        IP_inForm1->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        label = new QLabel(Form1);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 40, 51, 31));
        label->setStyleSheet(QString::fromUtf8("color: #F1C40F;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        Port_inForm1 = new QLineEdit(Form1);
        Port_inForm1->setObjectName("Port_inForm1");
        Port_inForm1->setGeometry(QRect(70, 80, 161, 31));
        Port_inForm1->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        label_2 = new QLabel(Form1);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 51, 31));
        label_2->setStyleSheet(QString::fromUtf8("color: #F1C40F;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 2px 2px;\n"
"border-radius: 5px;\n"
""));
        UserName_inform1 = new QLineEdit(Form1);
        UserName_inform1->setObjectName("UserName_inform1");
        UserName_inform1->setGeometry(QRect(30, 130, 201, 31));
        UserName_inform1->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        Passwor_inForm1 = new QLineEdit(Form1);
        Passwor_inForm1->setObjectName("Passwor_inForm1");
        Passwor_inForm1->setGeometry(QRect(30, 170, 201, 31));
        Passwor_inForm1->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        Passwor_inForm1->setEchoMode(QLineEdit::EchoMode::Password);
        BT_form1 = new QPushButton(Form1);
        BT_form1->setObjectName("BT_form1");
        BT_form1->setGeometry(QRect(80, 220, 80, 25));
        BT_form1->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        BT_form1->setMouseTracking(true);
        BT_form1->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        BT_form1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #F1C40F;\n"
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
        statusIcon_form1 = new QLabel(Form1);
        statusIcon_form1->setObjectName("statusIcon_form1");
        statusIcon_form1->setGeometry(QRect(230, 220, 22, 22));
        statusIcon_form1->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: red;\n"
"    border-radius: 10px;\n"
"    border: 1px solid black;\n"
"    min-width: 20px;\n"
"    min-height: 20px;\n"
"    max-width: 20px;\n"
"    max-height: 20px;\n"
"}\n"
""));
        Form_2 = new QGroupBox(centralwidget);
        Form_2->setObjectName("Form_2");
        Form_2->setGeometry(QRect(300, 60, 201, 181));
        Form_2->setCheckable(false);
        groupBox = new QGroupBox(Form_2);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 20, 181, 81));
        RB_Max = new QRadioButton(groupBox);
        RB_Max->setObjectName("RB_Max");
        RB_Max->setGeometry(QRect(10, 30, 61, 22));
        RB_Max->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        RB_min = new QRadioButton(groupBox);
        RB_min->setObjectName("RB_min");
        RB_min->setGeometry(QRect(10, 50, 71, 31));
        RB_min->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        RB_normal = new QRadioButton(groupBox);
        RB_normal->setObjectName("RB_normal");
        RB_normal->setGeometry(QRect(100, 30, 81, 21));
        RB_normal->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        RB_normal->setChecked(true);
        Rang_form2 = new QLineEdit(Form_2);
        Rang_form2->setObjectName("Rang_form2");
        Rang_form2->setGeometry(QRect(20, 110, 81, 31));
        Rang_form2->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        BT_form2 = new QPushButton(Form_2);
        BT_form2->setObjectName("BT_form2");
        BT_form2->setGeometry(QRect(20, 150, 80, 25));
        BT_form2->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        BT_form2->setMouseTracking(true);
        BT_form2->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        BT_form2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #F1C40F;\n"
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
        Form_3 = new QGroupBox(centralwidget);
        Form_3->setObjectName("Form_3");
        Form_3->setGeometry(QRect(510, 60, 191, 181));
        Form_3->setCheckable(false);
        groupBox_2 = new QGroupBox(Form_3);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 30, 81, 81));
        radioButton_4 = new QRadioButton(groupBox_2);
        radioButton_4->setObjectName("radioButton_4");
        radioButton_4->setGeometry(QRect(10, 30, 61, 22));
        radioButton_4->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName("radioButton_5");
        radioButton_5->setGeometry(QRect(10, 50, 71, 31));
        radioButton_5->setStyleSheet(QString::fromUtf8("QRadioButton {\n"
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
        BT_form3 = new QPushButton(Form_3);
        BT_form3->setObjectName("BT_form3");
        BT_form3->setGeometry(QRect(20, 120, 80, 25));
        BT_form3->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        BT_form3->setMouseTracking(true);
        BT_form3->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        BT_form3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #F1C40F;\n"
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
        doubleSpinBox = new QDoubleSpinBox(Form_3);
        doubleSpinBox->setObjectName("doubleSpinBox");
        doubleSpinBox->setGeometry(QRect(110, 70, 66, 29));
        doubleSpinBox->setStyleSheet(QString::fromUtf8("color: #ECF0F1;\n"
"font-size: 16px;\n"
"font-weight: bold;\n"
"background-color: #2C3E50;\n"
"padding: 4px 8px;\n"
"border-radius: 5px;\n"
""));
        doubleSpinBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        Form_4 = new QGroupBox(centralwidget);
        Form_4->setObjectName("Form_4");
        Form_4->setGeometry(QRect(710, 60, 191, 181));
        Form_4->setCheckable(false);
        pushButton_4 = new QPushButton(Form_4);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(20, 120, 80, 25));
        pushButton_4->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        pushButton_4->setMouseTracking(true);
        pushButton_4->setFocusPolicy(Qt::FocusPolicy::WheelFocus);
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"color: #F1C40F;\n"
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
        chartContainer = new QFrame(centralwidget);
        chartContainer->setObjectName("chartContainer");
        chartContainer->setGeometry(QRect(30, 300, 871, 291));
        chartContainer->setFrameShape(QFrame::Shape::StyledPanel);
        chartContainer->setFrameShadow(QFrame::Shadow::Raised);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 927, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Form1->setTitle(QCoreApplication::translate("MainWindow", "\331\201\330\261\331\205 \330\247\330\252\330\265\330\247\331\204", nullptr));
        IP_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "127.0.0.2", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "IP", nullptr));
        Port_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "12345", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "port", nullptr));
        UserName_inform1->setPlaceholderText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        Passwor_inForm1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        BT_form1->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        statusIcon_form1->setText(QString());
        Form_2->setTitle(QCoreApplication::translate("MainWindow", "\331\201\330\261\331\205 \331\205\330\255\330\247\330\263\330\250\330\247\330\252", nullptr));
        groupBox->setTitle(QString());
        RB_Max->setText(QCoreApplication::translate("MainWindow", "Max", nullptr));
        RB_min->setText(QCoreApplication::translate("MainWindow", "Min", nullptr));
        RB_normal->setText(QCoreApplication::translate("MainWindow", "Normal", nullptr));
        Rang_form2->setText(QString());
        Rang_form2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Range", nullptr));
        BT_form2->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        Form_3->setTitle(QCoreApplication::translate("MainWindow", "\331\201\330\261\331\205 \331\206\331\205\330\247\333\214\330\264", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "TypeChar", nullptr));
        radioButton_4->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        radioButton_5->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        BT_form3->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        Form_4->setTitle(QCoreApplication::translate("MainWindow", "\330\256\330\267", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
