#ifndef _SET_RAND_ARR_H
#define _SET_RAND_ARR_H

#include "stdlib.h"
template <typename T>
void setRandArr(T *p, const int iSize, T maxVal)
{
    if (!p)
        return;

    --p;
    for (int i = 0; i < iSize; ++i)
    {
        *++p = maxVal*(2.0*rand() / RAND_MAX - 1);
    }
}
#endif

