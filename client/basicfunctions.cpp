#include "basicfunctions.h"

BasicFunctions::BasicFunctions(){};

void BasicFunctions::AddColorItemToQcomBox(QComboBox *combox ,const QList<QColor> &colorsItem)
{
    for (const QColor &color : colorsItem)
    {
        QPixmap pixmap(24, 24);
        pixmap.fill(color);
        QIcon icon(pixmap);
        combox->addItem(icon,"");
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
