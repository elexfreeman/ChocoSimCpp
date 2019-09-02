#ifndef BASEPRODUCT_H
#define BASEPRODUCT_H

#include <Objects/Sys/baseobject.h>
#include <qdatetime.h>


namespace ChocoSim
{

class BaseProduct : public BaseObject
{
protected:
    bool isExpired; // продукт просрочен
public:

    int id;
    float basePrice; // себестоимость
    int shelfLife;  //срок годности в днях
    float massa; // масса


    BaseProduct(ErrorSys *pErrorSys, int *pNow);

    void fTick();

    void fPrint();

    bool fIsExpired();
};


}
#endif // BASEPRODUCT_H
