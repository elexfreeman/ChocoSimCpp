#ifndef BASEOBJECT_H
#define BASEOBJECT_H

#include "errorsys.h"
#include <QDebug>
#include <qstring.h>
#include <qdatetime.h>

namespace ChocoSim
{

/**
 * Базовый объект системы
 */
class BaseObject
{
private:
    bool bIsDeleted; //флаг удаления
public:

    QString sCaption; // название
    ErrorSys *errorSys; // ошибки выполнения
    int createAt; // день создания
    int *now; // текущий день

    /**
     * @brief BaseObject - базовый объект системы
     * @param pErrorSys - ошибки
     * @param pNow - ссылка на счетчик дней
     */
    BaseObject(ErrorSys *pErrorSys, int *pNow);

    /**
     * @brief setDeleted - удалить из системы
     */
    void setDeleted();


    bool fIsDeleted();

    /**
     * @brief fTick - Здесь описываются изменение состояние объекта во времени
     */
    void fTick();

    /**
     * @brief fPrint - печать объекта
     */
    void fPrint();

};


}


#endif // BASEOBJECT_H
