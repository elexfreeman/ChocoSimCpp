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
    qint64 createAt; // дата создания

    BaseObject(ErrorSys *pErrorSys);

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
