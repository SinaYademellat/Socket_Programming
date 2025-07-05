#include "loginhandler.h"

loginhandler::loginhandler(ClientClassTcp* clientData) : curentclient (clientData) {}


bool loginhandler::validateAndSet_IP (const QString &ip)
{
    if (ip.isEmpty ())
    {
        return false;
    }
    else
    {
        this->curentclient->_serverIP = ip;
        return true;
    }
}

bool loginhandler::validateAndSet_Port (QMainWindow *window, const QString &port)
{
    if (port.isEmpty ())
    {
        QMessageBox::warning (window, "مقدار پورت", "پورت خالی هست");
        return false;
    }
    else
    {
        //  =============================
        bool ok;
        quint16 valuePort = port.toUShort (&ok);
        if (ok)
        {
            this->curentclient->_serverPort = valuePort;
            return true;
        }
        else
        {
            QMessageBox::warning (window, "مقدار پورت", "لطفا برای پورت یک عدد  صیح مثبت باشد");
            return false;
        }
        //  =============================
    }
}


bool loginhandler::validateAndSet_username (const QString &username)
{
    if (username.isEmpty ())
    {
        return false;
    }
    else
    {
        this->curentclient->_userName = username;
        return true;
    }
}


bool loginhandler::validateAndSet_password (const QString &Password)
{
    if (Password.isEmpty ())
    {
        return false;
    }
    else
    {
        this->curentclient->_passWord = Password;
        return true;
    }
}


// ------------------


bool loginhandler::validateFormInputs (QMainWindow *window,
    const QString&                                  IP_input,
    const QString&                                  Port_input,
    const QString&                                  username_input,
    const QString&                                  password_input)
{
    // ----------- IP
    if(this->validateAndSet_IP (IP_input))
    {
        qDebug () << "IP is   :" << this->curentclient->_serverIP;
    }
    else
    {
        QMessageBox::warning (window, "خطا", "لطفا یک آدرس IP وارد کنید.");
        return false;
    }
    // ----------- Port
    if(this->validateAndSet_Port (window, Port_input))
    {
        qDebug () << "Port is:" << this->curentclient->_serverPort;
    }
    else
    {
        return false;
    }
    // -----------
    if(this->validateAndSet_username (username_input))
    {
        qDebug () << "username is:" << this->curentclient->_userName;
    }
    else
    {
        QMessageBox::warning (window, "خالی بودن فایل", " لطفا نام کاربری را وراد کنید");
        return false;
    }
    // -----------
    if(this->validateAndSet_password (password_input))
    {
        qDebug () << "Password is:" << this->curentclient->_passWord;
    }
    else
    {
        QMessageBox::warning (window, "خالی بودن فایل", " لطفا رمز را وراد کنید");
        return false;
    }
    // -----------
    return true;
}


void loginhandler::SetClient (ClientClassTcp *client)
{
    this->curentclient = client;
}
