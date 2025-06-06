#ifndef CLIENTCLASS_H
#define CLIENTCLASS_H
#include <QTcpSocket>
#include <QHostAddress>
#include "generatemessage.h"

class ClientClassTcp
{
private:
    QString _serverIP ;
    quint16 _serverPort ;
    generateMessage _generater;

// ----------------------------------------
    bool isValidIp();
    bool isValidPort();
    bool canConnectToServer();
    QString client_request();
public:
    QString uniqCode = "";
    ClientClassTcp();
    ClientClassTcp(QString serverIP_input, quint16 serverPort_input);
    void handle_client_request(int codeMessageIS , QStringList  parametersIS);

};

#endif // CLIENTCLASS_H
