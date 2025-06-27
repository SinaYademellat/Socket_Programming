#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include <QMainWindow>
#include <QtWidgets/QLineEdit>
#include <QMessageBox>


#include "clientclass.h"


class loginhandler
{
private :
    ClientClassTcp* curentclient = nullptr;

    bool _check_Ip_Gui(const QString &ip);
    bool _check_Port_Gui(QMainWindow *window,const QString &port);
    bool _check_Username_Gui(const QString &username);
    bool _check_Password_Gui(const QString &Password);

public:
    loginhandler(ClientClassTcp* clientData = nullptr);

    bool validateFormInputs(QMainWindow *window,const QString& IP_input,const QString& Port_input ,const QString& username_input ,const QString& password_input);

    void SetClient(ClientClassTcp* client);


};

#endif // LOGINHANDLER_H
