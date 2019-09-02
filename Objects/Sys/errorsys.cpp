#include "errorsys.h"

ErrorSys::ErrorSys()
{

}

void ErrorSys::error(QString sKey, QString sError)
{
  errorList[sKey] = sError;
  bOk = false;
};


QMap<QString, QString> ErrorSys::fGetErrorList()
{
  return errorList;
}

void ErrorSys::fClear()
{
  errorList.clear();
  bOk = true;
}

bool ErrorSys::isOk()
{
  return bOk;
};


