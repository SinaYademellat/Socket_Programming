#include "mainwindow.h"
#include "clientclass.h"
#include <QApplication>
#include <QDebug>

ClientClassTcp MainClientIs_Global;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
