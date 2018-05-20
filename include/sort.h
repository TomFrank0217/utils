#ifndef _SORT_H
#define _SORT_H
// ≤Œøº¡¥Ω”  http://www.cnblogs.com/eniac12/p/5329396.html#s12
#include "myMath.h"

/* √∞≈›≈≈–Ú */
template <typename T>
void bubbleSort(T *pArr, const int iSize){
    if (NULL == pArr || 2 > iSize){
        return;
    }

    for (int i = 0; i < iSize - 1; ++i){
        for (int j = 0; j < iSize - 1 - i; ++j){
            if (pArr[j] > pArr[j + 1]){
                swapF(pArr[j], pArr[j + 1]);
            }
        }
    }
}

/* º¶Œ≤æ∆≈≈–Ú */
template <typename T>
void cocktailSort(T *pArr, int iSize){
    if (NULL == pArr || 2>iSize){
        return;
    }
    
    int iLeft = 0, iRight = iSize - 1;
    int i = 0, j = 0;
    while (iLeft < iRight){
        for (i = iLeft; i < iRight; ++i){
            if (pArr[i]>pArr[i + 1]){
                swapF(pArr[i], pArr[i + 1]);
            }
        }
        --iRight;
        for (j = iRight; j > iLeft; j--){
            if (pArr[j] < pArr[j - 1]){
                swapF(pArr[j], pArr[j - 1]);
            }
        }
        ++iLeft;
    }
}

/* —°‘Ò≈≈–Ú */
template<typename T>
void selectionSort(T *pArr, int iSize){
    if (NULL == pArr || 2 > iSize){
        return;
    }
    int k = 0;
    for (int i = 0; i < iSize - 1; ++i){
        k = i;
        for (int j = i + 1; j < iSize; j++){
            if (pArr[j] < pArr[k]){
                k = j;
            }
        }
        swap(pArr[k], pArr[i]);
    }
}

/* ≤Â»Î≈≈–Ú */
template <typename T>
void insertionSort(T *pArr, int iSize){
    if (NULL == pArr || 2 > iSize){
        return;
    }

    for (int i = 1; i < iSize; ++i){
        int iRightHand = pArr[i];
        int j = i - 1;
        while (j >= 0){
            if (pArr[j]>iRightHand){
                swapF(pArr[j], pArr[j + 1]);
                --j;
            }
            else{
                break;
            }
        }
        pArr[j + 1] = iRightHand;
    }
}
#endif