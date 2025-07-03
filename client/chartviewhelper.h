#ifndef CHARTVIEWHELPER_H
#define CHARTVIEWHELPER_H

#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QValueAxis>
#include <QVBoxLayout>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtWidgets/QFrame>


/**
 * @brief   ترسیم نمودارهای خطی و ستونی با امکان فیلترهاگذاری
 *
 * این کلاس مجموعه‌ای از توابع برای رسم نمودارها را فراهم می‌کند
 * <br>
 * که دو مدل رسم نموداد (پیوسته و گسسته ) را پشتیبانی می‌کند
 * <br>
 * امکان فیلترگذاری هم به شکل کمینه، هم به شکل بیشینه، و هم به‌صورت هم‌زمان هر دو حالت وجود دارد
 */
class ChartViewHelper
{
private:
    /**
     * @brief تنظیم ظاهر و ویژگی‌های پایه نمودار
     * @param chart شی برای اعمال تنظیمات
     * @param chartFrame قاب نمایش نمودار در رابط گرافیکی
     */
    void setupChartAppearance(QChart *chart, QFrame *chartFrame);

    /**
     * @brief یافتن اولین داده‌ای که از آستانه عبور کرده است
     * @param curentindex اندیس شروع
     * @param data لیست داده‌ها
     * @param treshould مقدار آستانه
     * @return اندیس اولین داده‌ای که شرایط را دارد
     */
    int find_data_conect(int curentindex, QList<int> data, int treshould);
    /**
     * @brief محاسبه محل تقاطع
     * @param x0  نقطه اول
     * @param y0  نقطه اول
     * @param x1  نقطه دوم
     * @param y1  نقطه دوم
     * @param Y خط ثابت فیلتذر مد نظر
     * @return مقدار محل تقاطع نمودار با خط فیلتر
     */
    float findX(float x0, float y0, float x1, float y1, float Y );

    /**
     * @brief ساخت سری‌های کران بالا و کران پایین برای حساب کردن مساحت فیلترشده
     *
     * پس از مشخص شدن نقاط تقاطع خط فیلتر با نمودار
     * <br>
     * و مشخص شدن داده‌هایی که از خط فیلتر کم تر است
     * <br>
     * باید داده‌ها را به ترتیب در سریها قراردیم تا برای مرحله نمایش داده‌ها آماده‌شده‌باشند
     *
     * @param HitLine_X  نقاطی که نمودار با خط فیلتر برخورد کردند
     * @param X_low  نقاطی از نمدار که انداز آنها از فیلتر کوچکتر است
     * @param Y_low  مقادیر حاصل از
     * @param upperMask  خروجی
     * @param lowMask خروجی
     * @param Threshold_min  مقدار فیلتر
     *
     * @warning upperMask ,lowMask باید خالی باشد
     */
    void appendMaskedSeriesByLowerBound(QList<float>& HitLine_X, QList<float>& X_low, QList<int>&Y_low, QLineSeries *upperMask, QLineSeries *lowMask, int Threshold_min);
    //  ---------> min

    /**
     * @brief فیلتر پایین گذر برای حالت گسسته
     *
     * داده‌های ورودی که از مقدار آستانه کم‌تر یا مساوی‌ باشد
     * <br>
     * آن ستون را به کد رنگ مشخص شده تغییر رنگ می‌دهد
     *
     * @param chart_input  داده‌ها در این شی نمایش داده می‌شوند
     * @param DataForPlotIs  داده‌های ورودی
     * @param low_bound  کران پایین
     * @param low_colorCode کد رنگ کران پایین
     */
    void _plotChartWithMinFilter_BarChar(QChart *chart_input, const QList<int>& DataForPlotIs, int low_bound, int low_colorCode );
    /**
     * @brief فیلتر پایین گذر برای حالت پیوسته
     *
     * داده‌های ورودی که از مقدار آستانه کم‌تر یا مساوی‌ باشد
     * <br>
     * مساحت آن ناحیه را تعییر رنگ میدهد به رنگ دلخواه
     * @param chart_input  داده‌ها در این شی نمایش داده می‌شوند
     * @param DataForPlotIs  داده‌های ورودی
     * @param low_bound  کران پایین
     * @param low_colorCode کد رنگ کران پایین
     */
    void _plotChartWithMinFilter_LineChar(QChart *chart_input, const QList<int>& DataForPlotIs, int low_bound, int low_colorCode );


    /**
     * @brief ساخت سری‌های کران بالا و کران پایین برای حساب کردن مساحت فیلترشده
     *
     * همانند فیلتر پایین گذر است با این تفاوت که داده‌های بزرگتر یا مساوی مدنظر است
     *
     * @see	appendMaskedSeriesByLowerBound
     */
    void appendMaskedSeriesByUpperBound(QList<float>& HitLine_X, QList<float>& X_low, QList<int>&Y_low, QLineSeries *upperMask, QLineSeries *lowMask, int Threshold_max);
    //  ---------> Max

    /**
     * @brief  فیلتر بالا گذر برای حالت گسسته
     *
     * همانند فیلتر پایین گذر است با این تفاوت که داده‌های بزرگتر یا مساوی مدنظر است
     *
     * @see	_plotChartWithMinFilter_BarChar
     */
    void _plotChartWithMaxFilter_BarChar(QChart *chart_input, const QList<int>& DataForPlotIs, int Up_bound, int Up_colorCode );


    /**
     * @brief  فیلتر بالا گذر برای حالت پیوسته
     *
     * همانند فیلتر پایین گذر است با این تفاوت که داده‌های بزرگتر یا مساوی مدنظر است
     *
     * @see	_plotChartWithMinFilter_LineChar
     */
    void _plotChartWithMaxFilter_LineChar(QChart *chart_input, const QList<int>& DataForPlotIs, int Up_bound, int Up_colorCode );

    //  ---------> Both

    /**
     * @brief  فیلتر بالا گذر و پایین گذر برای حالت گسسته
     *
     *  این تابع امکان اعمال هم‌زمان فیلتر پایین‌گذر و بالاگذر را فراهم می‌کند
     * <br>
     * در واقع، این تابع ترکیبی از اجرای هم‌زمان فیلتر پایین‌گذر و بالاگذر است که بر روی داده‌ها پیاده‌سازی شده‌است
     *
     *
     * @param chart_input  داده‌ها در این شی نمایش داده می‌شوند
     * @param DataForPlotIs  داده‌های ورودی
     * @param low_bound  کران پایین
     * @param low_colorCode کد رنگ کران پایین
     * @param Up_bound  کران بالا
     * @param Up_colorCode کد رنگ کران بالا
     *
     * @see	_plotChartWithMaxFilter_BarChar
     * @see	_plotChartWithMinFilter_BarChar
     */
    void _plotChartWithMin_and_MaxFilte_BarChar(QChart *chart_input, const QList<int>& DataForPlotIs, int low_bound, int low_colorCode, int Up_bound, int Up_colorCode);


    /**
     * @brief  فیلتر بالا گذر و پایین گذر برای حالت پیوسته
     *
     *  این تابع امکان اعمال هم‌زمان فیلتر پایین‌گذر و بالاگذر را فراهم می‌کند
     * <br>
     * در واقع، این تابع ترکیبی از اجرای هم‌زمان فیلتر پایین‌گذر و بالاگذر است که بر روی داده‌ها پیاده‌سازی شده‌است
     *
     *
     * @param chart_input  داده‌ها در این شی نمایش داده می‌شوند
     * @param DataForPlotIs  داده‌های ورودی
     * @param low_bound  کران پایین
     * @param low_colorCode کد رنگ کران پایین
     * @param Up_bound  کران بالا
     * @param Up_colorCode کد رنگ کران بالا
     *
     * @see	_plotChartWithMaxFilter_LineChar
     * @see	_plotChartWithMinFilter_LineChar
     */
    void _plotChartWithMin_and_MaxFilte_LineChar(QChart *chart_input, const QList<int>& DataForPlotIs, int low_bound, int low_colorCode, int Up_bound, int Up_colorCode);


public:

    /**
     * @brief لیست رنگ‌های قابل انتخاب
     *
     * براساس این لیست آیتم‌های مربعی برای انتخاب رنگ فیلترها استفاده‌می‌شود
     *
     * @see  BasicFunctions::AddColorItemToQcomBox
     */
    QList<QColor>  colorsFor_colorCombo_IS = { Qt::red, Qt::green, Qt::blue, Qt::yellow, Qt::gray };


    /**
     * @brief حالت ترسیم نمودار
     *
     * مقادیر ممکن:
     * - 'L': نمودار خطی (Line) [پیشفرض]
     * - 'B': نمودار ستونی (Bar)
     */
    char mode = 'L';


    /**
     * @brief سازنده پیش‌فرض کلاس
     *
     */
    ChartViewHelper();

    /**
     * @brief نمایش داده‌ها ورودی
     *
     * براساس مد موجود داده‌های ورودی را نمایش می‌دهد
     *
     * @param chartFrame_input چارتی که داده‌ها در آن ذخیره ‌می‌شود
     * @param DataForPlotIs داده‌های برای نمایش
     *
     */
    void PlotChart(QFrame *chartFrame_input,  const QList<int>& DataForPlotIs);

    // ------------------------------------------

    /**
     * @brief فیلترپایین گذر برای داه‌ها
     *
     * با توجه به مد انتخاب شده فیلترپایین گذر برای حالت پیوسته یا گسسته نمایش داده‌ می‌شود
     *
     * @param chartFrame فریمی که داده‌ها در آن نمایش داده می‌شود
     * @param data داده‌های برای نمایش
     * @param minValue کران پایین
     * @param minColor کد رنگ انتخاب شده برای فیلتر
     *
     * @see	_plotChartWithMinFilter_BarChar
     * @see	_plotChartWithMinFilter_LineChar
     *
     */
    void plotChartWithMinFilter(QFrame *chartFrame, const QList<int>& data, int minValue, int minColor);

    /**
     * @brief فیلتربالا گذر برای داه‌ها
     *
     * با توجه به مد انتخاب شده فیلتربالا گذر برای حالت پیوسته یا گسسته نمایش داده‌ می‌شود
     *
     * @param chartFrame فریمی که داده‌ها در آن نمایش داده می‌شود
     * @param data داده‌های برای نمایش
     * @param maxValue کران بالا
     * @param maxColor کد رنگ انتخاب شده برای فیلتر
     *
     * @see	_plotChartWithMaxFilter_BarChar
     * @see	_plotChartWithMaxFilter_LineChar
     */
    void plotChartWithMaxFilter(QFrame *chartFrame, const QList<int>& data, int maxValue, int maxColor);

    /**
     * @brief هم‌زمان فیلتر پایین‌گذر و بالاگذر
     *
     * با توجه به مد انتخاب شده فیلتربالا گذر و پایین گذر برای حالت پیوسته یا گسسته نمایش داده‌ می‌شود
     *
     * @param chartFrame فریمی که داده‌ها در آن نمایش داده می‌شود
     * @param data داده‌های برای نمایش
     * @param minValue کران پایین
     * @param minColor کد رنگ انتخاب شده برای فیلتر
     * @param maxValue کران بالا
     * @param maxColor کد رنگ انتخاب شده برای فیلتر
     *
     * @see	_plotChartWithMin_and_MaxFilte_BarChar
     * @see	_plotChartWithMin_and_MaxFilte_LineChar
     */
    void plotChartWithMin_and_MaxFilter(QFrame *chartFrame, const QList<int>& data, int minValue, int minColor, int maxValue, int maxColor);
};

#endif // CHARTVIEWHELPER_H
