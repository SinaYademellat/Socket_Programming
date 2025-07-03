#ifndef GENERATEMESSAGE_H
#define GENERATEMESSAGE_H
#include <QString>
#include <QStringList>

/**
 * @brief کلاس ساخت پیام برای ارتباط با سرور
 *
 * این کلاس وظیفه دارد بر اساس کد نوع پیام و پارامترهای همراه، رشتهٔ نهایی پیام را تولید کند
 * <br>
 * بسته به نوع درخواست (مانند احراز هویت یا درخواست‌های پیش‌فرض)، پیام متفاوتی تولید خواهد شد
 * - Authentication << 1 userName password >>
 * - Data           << 2 Token  Mode Range >>
 */
class generateMessage
{
private:
    /**
     * @brief  نوع پیام
     *
     * مقدار عددی که مشخص می‌کند نوع درخواست چیست ( احراز هویت، دریافت اطلاعات)
     *
     */
    int codeMessage = -1;

    /**
     * @brief لیست پارامترهای همراه پیام
     *
     * داده‌های که بعد از عدد کد درخواست در درخواست کلاینت قرار میگیرد
     */
    QStringList parameters;

    /**
     * @brief تولید پیام احراز هویت
     *
     * از پارامترهای موجود برای ساختن رشته احراز هویت استفاده می‌شود
     * -  << 1 userName password >>
     * -  << 1 parameters[0] parameters[1] >>
     * @return رشته درخواست احراز هویت
     */
    QString generate_Authentication();

    /**
     * @brief تولید پیام دریافت اطلاعات
     *
     * از پارامترهای موجود برای ساختن رشته دریافت اطلاعات استفاده می‌شود
     * -  << 2 Token Mode Range >>
     * -  << 2 parameters[0] parameters[1] parameters[2]>>
     *
     * @return رشته درخواست دریافت اطلاعات
     */
    QString generate_DefaultRequest();

public:
    /**
     * @brief سازندهٔ پیش‌فرض کلاس
     */
    generateMessage();

    /**
     * @brief تعیین نوع پیام
     *
     * با استفاده از این تابع می‌توان مشخص کرد که پیام نهایی از چه نوعی درخواستی است
     *
     * @param codeIS عدد مشخص‌کنندهٔ نوع پیام
     */
    void setCodeMessage(int codeIS);
    /**
     * @brief تنظیم لیست پارامترهای پیام
     *
     * پارامترها می‌توانند شامل اطلاعات مختلفی
     * -  userName password
     * -  Token Mode Range
     *
     * @param par لیستی از رشته‌ها به‌عنوان پارامتر
     */
    void setParameters(QStringList par);

    /**
     * @brief  ساخت پیام نهایی برای ارسال
     *
     * این تابع براساس کد پیام و پارامترهای موجود، یکی از روش‌های داخلی تولید پیام را اجرا می‌کند
     * <br>
     * و پیام نهایی را برای ارسال به سرور آماده می‌سازد
     * @see generate_Authentication
     * @see generate_DefaultRequest
     * @return رشتهٔ نهایی پیام برای ارسال به سرور
     */
    QString Run();
};

#endif // GENERATEMESSAGE_H
