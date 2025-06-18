#ifndef BASICFUNCTIONS_H
#define BASICFUNCTIONS_H

#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>

class BasicFunctions
{

public:
    BasicFunctions();
    void AddColorItemToQcomBox(QComboBox *combox , const QList<QColor> &colorsItem);
    void SetGuiBlineBar(QSlider *myHorizonalSlider ,int minRang , int maxRang , int singleStep , int SetValue);
    void setServerStatusColor(QLabel *statusIcon ,QString colorIs );
};

#endif // BASICFUNCTIONS_H
