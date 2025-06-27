#ifndef BASICFUNCTIONS_H
#define BASICFUNCTIONS_H

#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>

/**
 * @brief مجموعه‌ای از توابع کمکی برای بهبود رابط گرافیکی برنامه
 *
 * برای افزودن رنگ، تنظیم نوار لغزنده و تغییر رنگ وضعیت سرور استفاده می‌شوند
 * بیشتر برای تسهیل و مرتب‌سازی کد در رابط کرافیکی است
 */
class BasicFunctions
{
public:
    BasicFunctions();

    /**
     * @brief افزودن رنگ‌ها
     *
     * این تابع یک لیست از رنگ‌ها را به عنوان آیتم به ورودی خود اضافه می‌کند
     *
     * @param combox متغییری که می‌خواهیم رنگ‌ها آنجا نمایش داده شود
     * @param colorsItem لیستی از رنگ‌های دلخواه
     *
     * @note کد رنگ‌ها می‌شود اندیس همین لیست رنگ‌ها که در کنار رنگ‌ها نمایش داده‌میشود
     */
    void AddColorItemToQcomBox(QComboBox *combox ,const QList<QColor> &colorsItem);

    /**
     * @brief مقداردهی به نوار لغزنده افقی
     *
     * برای زمانی  که کار بر می‌خواهد سرعت درخواست را تغییر دهد
     *
     * @param myHorizonalSlider اشاره‌گر به نوار لغزنده افقی
     * @param minRang مقدار حداقل
     * @param maxRang مقدار حداکثر
     * @param singleStep گام حرکت در هر بار تغییر
     * @param SetValue مقدار اولیه برای نوار لغزنده
     */
    void SetGuiBlineBar(QSlider *myHorizonalSlider ,int minRang , int maxRang , int singleStep , int SetValue);

    /**
     * @brief تغییر رنگ آیکون وضعیت سرور
     *
     * این تابع برای نمایش بصری وضعیت سرور به کار می‌رود؛ به‌طوری‌که با تغییر رنگ آیکون،
     * وضعیت سرور به‌صورت مستقیم قابل درک باشد
     *
     * @param statusIcon شاره‌گر به آیکون وضعیت
     * @param colorIs رشته‌ای که رنگ را مشخص می‌کند (مثلاً "green"، "red" و ...).
     *
     * @par مثال
     * @code
     * setServerStatusColor(statusIcon, "green"); // نمایش وضعیت "وصل بودن" سرور
     * @endcode
     */
    void setServerStatusColor(QLabel *statusIcon ,QString colorIs);
};


#endif // BASICFUNCTIONS_H
