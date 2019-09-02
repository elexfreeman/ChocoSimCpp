#ifndef BASEPRODUCT_H
#define BASEPRODUCT_H

#include <Objects/Sys/baseobject.h>
#include <qdatetime.h>


namespace ChocoSim
{

class BaseProduct : public BaseObject
{
public:

    int id;
    float basePrice; // себестоимость
    int shelfLife;  //срок годности в днях

    bool isExpired; // продукт просрочен
    float massa; // масса

    BaseProduct(ErrorSys *pErrorSys);

    void fTick();

    void fPrint();
};


}
#endif // BASEPRODUCT_H
