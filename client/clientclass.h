#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <QTcpSocket>
#include <QHostAddress>
#include "generatemessage.h"

class ClientClassTcp
{
private:
    generateMessage _generater;
    // ----------------------------------------
    bool isValidIp();
    bool isValidPort();
    bool canConnectToServer();
    QString client_request();
public:
    QString _serverIP ;
    quint16 _serverPort ;
    QString _userName = "";
    QString _passWord = "";
    QString token = "";

    QList<int>  server_anserData;

    ClientClassTcp();
    ClientClassTcp(QString serverIP_input, quint16 serverPort_input);
    void handle_client_request(int codeMessageIS , QStringList  parametersIS);

    // *************** Windo *****************
    bool Connection = false;
    bool passwordAndUsername = false;


};

#endif // CLIENTCLASS_H
