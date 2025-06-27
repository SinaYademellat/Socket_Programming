#include "generatemessage.h"

// -------------------------------------------------------
generateMessage::generateMessage()
{
    this->codeMessage = -1;
    this->parameters.clear();
}
// -------------------------------------------------------


//  +++++++++++++++ << public >> ++++++++++++++

// ~~~~~~~~~~~~~
QString generateMessage::generate_Authentication()
{
    //  (1)  code: << 1 userName password >>
    QString resultIs = QString("1 %1 %2").arg(this->parameters[0], this->parameters[1]);
    return resultIs;
}
// ~~~~~~~~~~~~~
QString generateMessage::generate_DefaultRequest()
{
    //  (2)  code: << 2 Token  Mode Range >>
    QString resultIs = QString("2 %1 %2 %3").arg(this->parameters[0],this->parameters[1],this->parameters[2]);
    return resultIs;
}
// ~~~~~~~~~~~~~

//  +++++++++++++++ << public >> ++++++++++++++

// ~~~~~~~~~~~~~
void generateMessage::setCodeMessage(int codeIS)
{
    this->codeMessage = codeIS;
}
// ~~~~~~~~~~~~~
void generateMessage::setParameters(QStringList par)
{
    this->parameters = par;
}
// ~~~~~~~~~~~~~
QString generateMessage::Run()
{
    switch (this->codeMessage)
    {
    case 1:
        return this->generate_Authentication();
        break;
    case 2:
        return this->generate_DefaultRequest();
        break;

    default:
        // qDebug()<<"Error --> (generateMessage)";
        return "-1";
        break;
    }
}
// ~~~~~~~~~~~~~
