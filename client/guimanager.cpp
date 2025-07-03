#include "guimanager.h"
#include "basicfunctions.h"

GuiManager::GuiManager() {}

void GuiManager::showLoginForm (QMainWindow *window, QList<QFrame *> forms)
{
    for (QFrame* f : forms)
    {
        if(f)
        {
            f->hide ();
        }
    }
    window->setGeometry (20, 30, 419, 551);
}

void GuiManager::showMainForm (QMainWindow *window, QFrame *loginFrame, QList<QFrame *> mainForms, QList<QColor>  colorsFor_colorCombo,
    QComboBox *colorCombox_1_Max, QComboBox *colorCombox_2_Min, QSlider *horizontalSlider_FPS, QLabel *label_FPSValue)
{
    window->resize (1389, 605);

    for (QFrame* f : mainForms)
    {
        if(f)
        {
            f->show ();
        }
    }

    loginFrame->hide ();

    // this->creat_GUi_Form3and4();
    BasicUI::AddColorItemToQcomBox (colorCombox_1_Max, colorsFor_colorCombo);
    BasicUI::AddColorItemToQcomBox (colorCombox_2_Min, colorsFor_colorCombo);
    // ------------
    BasicUI::SetGuiBlineBar (horizontalSlider_FPS, 1, 100, 1, 100);
    // ------------
    window->connect (horizontalSlider_FPS, &QSlider::valueChanged, window, [=](int value){
        double decimalValue = value / 100.0;
        label_FPSValue->setText (QString::number (decimalValue, 'f', 2));
    });
}
