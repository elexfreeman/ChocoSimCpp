#include "baseobject.h"




ChocoSim::BaseObject::BaseObject(ErrorSys *pErrorSys)
{
    errorSys = pErrorSys;
    bIsDeleted = false;
    createAt =  QDateTime::currentMSecsSinceEpoch(); // дата создания
}

void ChocoSim::BaseObject::setDeleted()
{
    bIsDeleted = true;
}

bool ChocoSim::BaseObject::fIsDeleted()
{
    return bIsDeleted;
}

void ChocoSim::BaseObject::fTick()
{
    qDebug() << "HI! This is: " << sCaption;
}

void ChocoSim::BaseObject::fPrint()
{
    qDebug() << sCaption;
}
