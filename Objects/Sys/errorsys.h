#ifndef ERRORSYS_H
#define ERRORSYS_H
#include <QMap>

class ErrorSys
{
private:
    bool bOk;
    QMap<QString, QString> errorList;

public:
    ErrorSys();

    void error(QString sKey, QString sError);
    QMap<QString, QString> fGetErrorList();
    void fClear();
    bool isOk();

};

#endif // ERRORSYS_H
