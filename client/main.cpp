#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QString>

void loadStyleSheet (QApplication& app)
{
    QFile file (":/styles/style.qss");
    if (file.open (QFile::ReadOnly | QFile::Text))
    {
        QString style = QString::fromUtf8 (file.readAll ());
        app.setStyleSheet (style);
    }
}


int main (int argc, char *argv[])
{
    QApplication a (argc, argv);
    loadStyleSheet (a);
    MainWindow w;
    w.show ();
    return a.exec ();
}
