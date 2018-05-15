#include "setRandVal.h"
#include <time.h>
#include <stdlib.h>
void setRandVal(DATA_TYPE *p, int iSize, DATA_TYPE maxVal)
{
    if (!p)
        return;

    --p;
    for (int i = 0; i < iSize; ++i)
    {
        *++p = maxVal*(2.0*rand() / RAND_MAX - 1);
    }
}