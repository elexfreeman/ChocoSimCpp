#include "core.h"



ChocoSim::Core::Core(ChocoSim::EventMaker *pEventMaker, ErrorSys *pErrorSys)
{
    eventMaker = pEventMaker;
    errorSys = pErrorSys;
    errorSys->fClear();
    *now = 0;
}

ChocoSim::Core::~Core()
{
    delete eventMaker;
    delete errorSys;
}

void ChocoSim::Core::fAdd(ChocoSim::BaseObject *object)
{
    eventMaker->fAdd(object);
}

void ChocoSim::Core::fTick()
{
    // обрабатываем свой тик
    // ...

    // обрабатываем тики объектов
    (*now)++;
    eventMaker->fTick();
}
