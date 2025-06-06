#include "mainwindow.h"
#include "clientclass.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    ClientClassTcp testClient;
    //    qDebug() << testClient.canConnectToServer();

    //    >>>>>>>> Test1
    int Global_code = 1;
    QStringList parr1;
    parr1 << "your_username" <<"your_password";
    testClient.handle_client_request(Global_code,parr1);
    qDebug()<<"*****************";
    QStringList parr2;
    for (int i =0 ; i<=1;i++)
    {
        Global_code = 2;
        parr2 <<testClient.uniqCode << "Normal" <<"2";
        testClient.handle_client_request(Global_code,parr2);
        parr2.clear();
        qDebug()<<"*****************";
    }
   Global_code = 2;
   parr2 <<testClient.uniqCode << "Min" <<"50";
   testClient.handle_client_request(Global_code,parr2);
   parr2.clear();
   qDebug()<<"*****************";
   Global_code = 2;
   parr2 <<testClient.uniqCode << "Max" <<"50";
   testClient.handle_client_request(Global_code,parr2);
   parr2.clear();

    return a.exec();
}
