#include "clientclass.h"
#include <QTcpSocket>
#include <QRegularExpression>

ClientClassTcp::ClientClassTcp()
{
    this->_serverIP = "127.0.0.2";
    this->_serverPort = 12345;
    this->server_anserData.clear();
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
QString ClientClassTcp::send_client_request()
{

    QTcpSocket _socket;
    _socket.connectToHost(_serverIP, _serverPort);
    if (!_socket.waitForConnected(2000))
    {
        qDebug() << "Connection failed:" << _socket.errorString();
        return "Connection failed";
    }
    qDebug()<<"[try] " << "Connect " << _serverIP << ":" << _serverPort <<"...";

    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    QString message = this->_generater.Run();
    qDebug() << "MessageIS " <<message;
    //  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


    _socket.write(message.toUtf8());
    _socket.flush();

    if (_socket.waitForReadyRead(3000))
    {
        QByteArray response = _socket.readAll();
        qDebug() << "Server Anser :" << QString::fromUtf8(response);
        _socket.close();
        qDebug() << " ~~~~~~~~~~~~~~~~~~~~~ << finish >> ~~~~~~~~~~~~~~~~~~~~~ ";
        this->Connection = true;
        return  QString::fromUtf8(response);;
    }
    else
    {
        qDebug() << "time out from server";
        this->Connection = false;
        _socket.close();
        return "time out from server";
    }

}

// +++++++++++++++ << public >> ++++++++++++++

void ClientClassTcp::handle_client_request(int codeMessageIS , QStringList  parametersIS)
{
    this->_generater.setCodeMessage(codeMessageIS);
    this->_generater.setParameters(parametersIS);

    QString Server_Anser = this->send_client_request();


    if((Server_Anser == "Connection failed")  || Server_Anser == "time out from server")
    {
        this->Connection= false;
        return;
    }

    switch (codeMessageIS)
    {
    case 1:{
        if(Server_Anser == "-1")
        {
            qDebug()<<"wrong password or userName";
            this->passwordAndUsername= false;
        }
        else
        {
            qDebug()<<"NewPassword: "<<Server_Anser;
            this->token = Server_Anser;
            this->passwordAndUsername= true;
        }
        break;
    }
    case 2:{
        qDebug()<<Server_Anser;
        QStringList parts = Server_Anser.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        this->server_anserData.clear();
        for (const QString &part : std::as_const(parts))
        {
            this->server_anserData.append(part.toInt());
        }
        break;
    }

    default:
        {
        qDebug()<<"";
        break;
        }
    }

    return;

}
