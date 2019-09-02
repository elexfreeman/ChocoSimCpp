#include "baseproduct.h"


ChocoSim::BaseProduct::BaseProduct(ErrorSys *pErrorSys, int *pNow): BaseObject (pErrorSys, pNow)
{
    isExpired = false;
    basePrice = 0.0;
    shelfLife = 1;
    massa = 0.0;

}

bool ChocoSim::BaseProduct::fIsExpired()
{
    return false;
}
