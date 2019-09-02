#ifndef EVENTMAKER_H
#define EVENTMAKER_H

#include "baseobject.h"

#include <QVector>

namespace ChocoSim
{


class EventMaker
{
private:



public:
    EventMaker();
    ~EventMaker();

    /* массив обрабатываемых объектов */
    QVector<BaseObject *> objects;

    /**
     * @brief fAdd - добавить объект в систему
     * @param item
     */
    void fAdd(BaseObject *item);

    /**
     * @brief fTick - обработать тики объектов
     */
    void fTick();

    /**
     * @brief fPrint - печать всех объектов системы
     */
    void fPrint();


};


}
#endif // EVENTMAKER_H
