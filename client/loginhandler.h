#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QMessageBox>


#include "clientclass.h"


/**
 * @brief کلاس بررسی و مدیریت ورود کاربران
 *
 * این کلاس مسئول بررسی اطلاعات واردشده در فرم ورود و اعتبارسنجی آن‌ها است
 *
 */
class loginhandler
{
private:

    ClientClassTcp* curentclient = nullptr;

    bool validateAndSet_IP(const QString &ip);
    bool validateAndSet_Port(QMainWindow *window, const QString &port);
    bool validateAndSet_username(const QString &username);
    bool validateAndSet_password(const QString &Password);

public:
    /**
     * @brief سازنده کلاس
     *
     *
     * @param clientData اشاره‌گر به کلاینت برای ذخیره سازی تغییرات اعمال شده
     */
    loginhandler(ClientClassTcp* clientData = nullptr);

    /**
     * @brief تنظیم یا تغییر کلاینت
     *
     * این تابع کلاینت جاری را تغییر می‌دهد تا اطلاعات جدید در آن آدرس جدید ذخیره شوند
     *
     * @param client اشاره‌گر به کلاینت جدید
     */
    void SetClient(ClientClassTcp* client);


    /**
     * @brief بررسی و اعتبارسنجی فرم‌های ورود
     *
     *  در این تابع به کمک توابع داخلی برسی می‌شود که آیا همه فرم‌های ورودی تکمیل شده‌اند یا خیر
     * <br>
     * در صورت تکمیل بودن فیلدهای ورودی، اطلاعات کاربر در شی کلاینت ذخیره می‌شود تا برای ارسال به سرور آماده گردد
     *
     * @param window پنجره گرافیکی اصلی برای نمایش هشدار
     * @param IP_input رشته‌ی وارد شده برای آی پی
     * @param Port_input رشته‌ی وارد شده برای پورت
     * @param username_input نام کاربری وارد شده
     * @param password_input رمز عبور وارد شده
     *
     * @return `true` اگر همه ورودی‌ها معتبر باشند
     * @return `false`  در غیر این صورت
     */
    bool validateFormInputs(QMainWindow *window, const QString& IP_input, const QString& Port_input, const QString& username_input, const QString& password_input);
};

#endif // LOGINHANDLER_H
