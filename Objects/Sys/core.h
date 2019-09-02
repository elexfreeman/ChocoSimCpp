#ifndef CORE_H
#define CORE_H

#include "eventmaker.h"

#include <QDateTime>

namespace ChocoSim
{

class Core
{
private:

public:
    int *now; // текущий день
    EventMaker *eventMaker;
    ErrorSys *errorSys;


    Core(EventMaker *pEventMaker, ErrorSys *pErrorSys);
    ~Core();

    /**
     * @brief fAdd - добавить объект в систему
     * @param object
     */
    void fAdd(BaseObject *object);

    /**
     * @brief fTick - обработать тики объектов
     */
    void fTick();
};


}

#endif // CORE_H
