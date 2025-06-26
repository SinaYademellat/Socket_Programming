#include "basicfunctions.h"

BasicFunctions::BasicFunctions(){};

void BasicFunctions::AddColorItemToQcomBox(QComboBox *combox ,const QList<QColor> &colorsItem)
{
    // mycode { Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::gray };
    // 0 --> Red
    // ....
    // 4 --> Gray
    int code = 0 ;
    for (const QColor &color : colorsItem)
    {
        QPixmap pixmap(24, 24);
        pixmap.fill(color);
        QIcon icon(pixmap);
        combox->addItem(icon, QString::number(code));
        code+=1;
    }
}

void  BasicFunctions::SetGuiBlineBar(QSlider *myHorizonalSlider ,int minRang , int maxRang , int singleStep , int SetValue)
{
    myHorizonalSlider->setMinimum(minRang);
    myHorizonalSlider->setMaximum(maxRang);
    myHorizonalSlider->setSingleStep(singleStep);
    myHorizonalSlider->setValue(SetValue);
    // ------------------------------------------
}

void BasicFunctions::setServerStatusColor(QLabel *statusIcon, QString colorIs)
{

    QString style = QString(
                        "QLabel {"
                        "background-color: %1;"
                        "border-radius: 10px;"
                        "border: 1px solid black;"
                        "}").arg(colorIs);

    statusIcon->setStyleSheet(style);
}
