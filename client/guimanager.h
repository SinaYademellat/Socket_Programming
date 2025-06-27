#ifndef GUIMANAGER_H
#define GUIMANAGER_H

#include <QFrame>
#include <QMainWindow>
#include <QList>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>

#include "basicfunctions.h"
#include "chartviewhelper.h"

class GuiManager
{

public:
    GuiManager();

    void showLoginForm(QMainWindow *window, QList<QFrame*> forms);

    void showMainForm(
                      QMainWindow *window,
                      QFrame *loginFrame, QList<QFrame *> mainForms ,
                      QList<QColor>  colorsFor_colorCombo ,  BasicFunctions mybasicfunctis,
                      QComboBox *colorCombox_1_Max , QComboBox *colorCombox_2_Min ,
                      QSlider *horizontalSlider_FPS, QLabel *label_FPSValue
                      );

};

#endif // GUIMANAGER_H
