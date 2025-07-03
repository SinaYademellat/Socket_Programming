#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "basicfunctions.h"
#include "chartviewhelper.h"
#include "clientclass.h"
#include "guimanager.h"
#include "loginhandler.h"


QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_form1_Loggin_clicked();
    void on_pushButton_form2_clicked();
    void on_pushButton_form3_clicked();
    void on_pushButton_form4_Filter_clicked();
    void on_pushButton_form4_Clean_clicked();


private:

    Ui::MainWindow *ui;

    // ------------------------------------------
    ChartViewHelper chartTest1;
    ClientClassTcp MainClientIs_Global;
    GuiManager guiManager;
    loginhandler loginManager;

    // ------------------------------------------


    /**
     * @brief بررسی خالی نبودن فیلدهای ضروری در فرم ورود
     *
     * این تابع بررسی می‌کند که فیلدهای ضروری مانند آی‌پی سرور، پورت، نام کاربری و رمز عبور
     * <br>
     * توسط کاربر به‌درستی پر شده باشند یا خیر.
     * <br>
     * در صورت خالی بودن هر کدام، پیغام هشدار به کاربر نمایش داده می‌شود
     *
     * @return `true` اگر تمام فیلدهای ضروری پر شده باشند
     * @return `false` در غیر این صورت
     *
     */
    bool verifyRequiredFields();

    /**
     * @brief بررسی امکان دسترسی به داشبورد برنامه
     *
     * این تابع بررسی می‌کند که آیا شرایط لازم برای ورود به بخش داشبورد مهیا است یا خیر
     * <br>
     * این شرایط شامل اتصال موفق به سرور، ورود صحیح نام کاربری و رمز عبور
     *
     * @return `true` اگر دسترسی به داشبورد ممکن باشد
     * @return `false` در غیر این صورت
     */
    bool canEnterDashboard();

    // ------------------------------------------

    /**
     * @brief به‌روزرسانی نمودار با داده‌های جدید
     *
     * این تابع وظیفه دارد نمودار موجود در رابط کاربری را با داده‌های تازه دریافتی از سرور به‌روزرسانی کند
     * <br>
     * ابتدا فریم را پاک کرده
     * <br>
     * سپس حالت نمودار را برسی کرده
     *<br>
     * در نهایت یک جدول جدید با داده‌های جدید ساخته
     * @see ChartViewHelper::PlotChart
     */
    void updateChart();


    /**
     * @brief بازسازی نمودار موجود
     *
     * در این تابع فریمی که نمودا نمایش داده می‌شود را پاک کرده و برای داده‌های جدید آماده کرده
     */
    void _Refresh_chart();

    /**
     * @brief تعیین نوع نمایش نمودار (خطی یا ستونی)
     *
     * بسته به تنظیمات انتخاب‌شده در رابط کاربری، این تابع مشخص می‌کند که نمودار به صورت خطی یا ستونی نمایش داده شود.
     */
    void _SetModeOFChart();

    /**
     * @brief نمونه‌برداری از داده‌ها با تمرکز بر مقادیر بیشینه
     *
     * با فراخوانی اگر بازه عدد مقسوم‌علیه ۱۰۰ باشد
     * <br>
     * پیام درخواست داده برای حالت بیشینه را آماده کرده و به ارسال کننده انتقال داده
     * @see ClientClassTcp::handle_client_request
     */
    void _Sampling_Maximum_Ui();

    /**
     * @brief نمونه‌برداری از داده‌ها با تمرکز بر مقادیر کمینه
     *
     * با فراخوانی اگر بازه عدد مقسوم‌علیه ۱۰۰ باشد
     * <br>
     * پیام درخواست داده برای حالت کمینه را آماده کرده و به ارسال کننده انتقال داده
     * @see ClientClassTcp::handle_client_request
     */
    void _Sampling_Minimum_Ui();


    /**
     * @brief حالت بدون نمونه برداری
     *
     * در این پیام درخواست داده در حالت نرمال ساخته می‌شود
     *
     */
    void _Sampling_Normal_Ui();

    /**
     * @brief نمايش وضعیت سرور بر اساس پاسخ دریافتی از سرور
     *
     * این تابع پس از ارسال درخواست‌های دریافت اطلاعات( درخواست‌هاي با کد درخواست دو) فعال می‌شود
     * <br>
     *  باتوجه به اینکه سرور وصل است یا نه رنگ لیبل وضعیت سرور در فرم‌ها تغییر می‌کند
     *
     */
    void _Server_Satution_For_requestCode2();

    // ------------------------------------------

    /**
     * @brief  اجرای متناوب درخواست داده
     *
     * این نخ یا همان تایمر برای پیاده‌سازی امکان ارسال درخواست به سرور بصورت متناوب است
     *
     */
    QTimer *timer = nullptr;

    /**
     * @brief به‌روزرسانی  یک نخ (Thread)
     *
     * در صورتی که نخ در حال اجرا باشد، آن را مجدداً به‌روزرسانی می‌کند تا از اجرای صحیح اطمینان حاصل شود.
     */
    void _RefreshThread();


    /**
     * @brief پرچم نشان‌دهنده انتظار برای تکمیل یک نخ (Thread)
     *
     * زمانی که کاربر یک ورودی اشتباهی وارد می‌کند نخ به حالت انتظار می‌رود
     * <br>
     * در این زمان این پرچم فعال می‌شود تا چند بار خطا را نمایش داده نشود
     * <br>
     *  و این متغییر تا زمانی که کاربر داده صحیح وارد کند فعال است
     *
     */
    bool _flag_wait_Thread = false;

    // ---------------------
};
#endif // MAINWINDOW_H
