#include "baseobject.h"




ChocoSim::BaseObject::BaseObject(ErrorSys *pErrorSys, int *pNow)
{
    errorSys = pErrorSys;
    now = pNow;
    bIsDeleted = false;
    createAt =  *pNow; // дата создания
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

    qDebug() << *now << ": HI! This is: " << sCaption;
}

void ChocoSim::BaseObject::fPrint()
{
    qDebug() << sCaption;
}
