#include "clientclass.h"
#include <QTcpSocket>

ClientClassTcp::ClientClassTcp()
{
    this->_serverIP = "127.0.0.2";
    this->_serverPort = 12345;
}

ClientClassTcp::ClientClassTcp(QString serverIP_input, quint16 serverPort_input)
{
    this->_serverIP = serverIP_input;
    this->_serverPort = serverPort_input;
}

// +++++++++++++++ << private >> ++++++++++++++

bool ClientClassTcp::isValidIp() {
    QHostAddress address;
    return address.setAddress(_serverIP);
}
// ----------
bool ClientClassTcp::isValidPort() {
    return ((_serverPort >= 0) && (_serverPort <= 65535));
}
// ----------
bool ClientClassTcp::canConnectToServer() {
    if (!isValidIp() || !isValidPort())
        return false;

    QTcpSocket _socket;
    _socket.connectToHost(_serverIP, _serverPort);

    if (!_socket.waitForConnected(2000))
    {
        qDebug() << "Connection failed:" << _socket.errorString();
        return false;
    }
    qDebug()<<"[+] " << "Connect " << _serverIP << ":" << _serverPort <<"...";
    _socket.close();
    return true;
}
// ----------
QString ClientClassTcp::client_request()
{

    QTcpSocket _socket;
    _socket.connectToHost(_serverIP, _serverPort);
    if (!_socket.waitForConnected(2000))
    {
        qDebug() << "Connection failed:" << _socket.errorString();
        return "Connection failed";
    }
    qDebug()<<"[+] " << "Connect " << _serverIP << ":" << _serverPort <<"...";

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QString message = this->_generater.Run();
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    _socket.write(message.toUtf8());
    _socket.flush();

    if (_socket.waitForReadyRead(3000))
    {
        QByteArray response = _socket.readAll();
        qDebug() << "Server Anser :" << QString::fromUtf8(response);
        _socket.close();
        qDebug() << " ~~~~~~~~~~~~~~~~~~~~~ << finish >> ~~~~~~~~~~~~~~~~~~~~~ ";
        return  QString::fromUtf8(response);;
    }
    else
    {
        qDebug() << "time out from server";
         _socket.close();
         return "time out from server";
    }

}

// +++++++++++++++ << public >> ++++++++++++++

void ClientClassTcp::handle_client_request(int codeMessageIS , QStringList  parametersIS)
{
        this->_generater.setCodeMessage(codeMessageIS);
        this->_generater.setParameters(parametersIS);

        QString Server_Anser = this->client_request();


        if((Server_Anser == "Connection failed")  || Server_Anser == "time out from server")
            {return;}



        switch (codeMessageIS)
        {
        case 1:
                if(Server_Anser=="-1")
                {
                    qDebug()<<"wrong password or userName";
                }
                else
                {
                    qDebug()<<"NewPassword: "<<Server_Anser;
                    this->uniqCode = Server_Anser;
                }
                break;
        default:
            break;
        }

        return;

}


