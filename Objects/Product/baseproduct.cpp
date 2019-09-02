#include "baseproduct.h"


ChocoSim::BaseProduct::BaseProduct(ErrorSys *pErrorSys): BaseObject (pErrorSys)
{
    isExpired = false;
}
