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


/**
 * @brief کلاس کمکی برای رابط گرافیکی برنامه
 *
 * این کلاس مسئول نمایش فرم‌های مختلف برنامه مانند فرم ورود یا فرم اصلی است
 * <br>
 * همچنین وظیفه مقداردهی اولیه به برخی ابزارهای رابط کاربری مانند کمبوباکس رنگ‌ها برای فیلتر‌های رنگی و اسلایدر سرعت ارسال درخواست داده را دارد
 */
class GuiManager
{

public:

    /**
     * @brief سازنده پیش‌فرض کلاس
     *
     * این سازنده بدون پارامتر بوده و برای ساخت یک نمونه از کلاس مدیریت گرافیک استفاده می‌شود
     */
    GuiManager();

     /**
     * @brief نمایش فرم ورود و مخفی‌سازی فرم‌های اصلی
     *
     * این تابع فرم ورود را نمایش داده و فرم‌های اصلی برنامه را مخفی می‌کند
     *
     * @param window پنجره‌ی اصلی برنامه
     * @param forms لیستی از فرم‌هایی که باید مخفی شوند
     */
    void showLoginForm(QMainWindow *window, QList<QFrame*> forms);


    /**
     * @brief نمایش فرم‌های اصلی برنامه و مخفی کردن فرم ورود
     *
     * این تابع پس از ورود موفق، فرم ورود را مخفی کرده و فرم‌های اصلی برنامه را نمایش می‌دهد.
     *
     * @param window پنجره‌ی اصلی برنامه
     * @param loginFrame فرم ورود که باید مخفی شود
     * @param mainForms لیست فرم‌های اصلی که باید نمایش داده شوند
     * @param colorsFor_colorCombo لیست رنگ‌هایی که در کمبوباکس‌ها نمایش داده می‌شوند
     * @param mybasicfunctis شی ابزارهای توابع کمکی
     * @param colorCombox_1_Max کمبوباکس انتخاب رنگ برای فیلتر بالاگذر
     * @param colorCombox_2_Min کمبوباکس انتخاب رنگ برای فیلتر پایین‌گذر
     * @param horizontalSlider_FPS اسلایدر تنظیم سرعت درخواست داده
     * @param label_FPSValue لیبل نمایش مقدار فعلی سرعت درخواست داده
     */
    void showMainForm(
                      QMainWindow *window,
                      QFrame *loginFrame, QList<QFrame *> mainForms ,
                      QList<QColor>  colorsFor_colorCombo ,  BasicFunctions mybasicfunctis,
                      QComboBox *colorCombox_1_Max , QComboBox *colorCombox_2_Min ,
                      QSlider *horizontalSlider_FPS, QLabel *label_FPSValue
                      );

};

#endif // GUIMANAGER_H
