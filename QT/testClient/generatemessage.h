#ifndef GENERATEMESSAGE_H
#define GENERATEMESSAGE_H
#include <QString>
#include <QStringList>

class generateMessage
{
private:
    int codeMessage = -1;
    QStringList parameters ;

    QString generate_Authentication();
    QString generate_DefaultRequest();

public:
    generateMessage();
    void setCodeMessage(int codeIS);
    void setParameters(QStringList par);
    QString Run();

};

#endif // GENERATEMESSAGE_H
