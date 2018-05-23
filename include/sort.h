#ifndef _SORT_H
#define _SORT_H
// 参考链接  http://www.cnblogs.com/eniac12/p/5329396.html#s12
#include "myMath.h"

/* 冒泡排序 */
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

/* 鸡尾酒排序 */
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

/* 选择排序 */
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

/* 插入排序 */
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

/* 归并排序 每次MergeSort(pArr, copy, start, end);之后,pArr 在[start,end) 区间已经有序 */

template <typename T>
void MergeSort(T *pArr, T *copy, int start, int end){
    if (1 >= end - start){
        //copy[start] = pArr[start];
        return;
    }

    int mid = (start + end) / 2;
    MergeSort(pArr, copy, start, mid);
    MergeSort(pArr, copy, mid, end);
    for (int i = start; i<end; ++i){
        copy[i] = pArr[i];
    }
    int i = start, j = mid, k = start;
    while (i < mid&&j < end){
        if (copy[i] < copy[j]){
            pArr[k++] = copy[i++];
        }
        else{
            pArr[k++] = copy[j++];
        }
    }

    while (i < mid){
        pArr[k++] = copy[i++];
    }
    while (j < end){
        pArr[k++] = copy[j++];
    }
}
template <typename T>
void mergeSort(T *pArr, int iSize){
    if (NULL == pArr || 2 > iSize){
        return;
    }
    T *copy = new T[iSize];
    MergeSort(pArr, copy, 0, iSize);
    delete[] copy;
    copy = NULL;
}
template <typename T>
void shellSort(T *pArr, int iSize){
    if (NULL == pArr || 2 > iSize){
        return;
    }

    int gap = iSize / 2;
    while (1 <= gap){
        for (int i = gap; i < iSize; ++i){
            int target = pArr[i];
            int j = i - gap;
            while (j >= 0 && pArr[j] > target){
                swapF(pArr[j], pArr[j + gap]);
                j -= gap;
            }
            pArr[j + gap] = target;
        }
        gap /= 2;
    }
}


template <typename T>
void keepHeap(T *p, int root, int iSize){
    int mid = root;
    int left = 0, right = 0;
    int index = 0;
    while (mid < iSize / 2){
        index = mid;
        left = mid * 2 + 1;
        right = left + 1;
        if (/*left<iSize&&*/p[left]>p[index]){
            index = left;
        }
        if (right<iSize&&p[right]>p[index]){
            index = right;
        }
        if (mid == index){
            break;
        }
        else{
            swapF(p[mid], p[index]);
            mid = index;
        }
    }
}
template <typename T>
void buildHeap(T *p, int iSize){
    for (int i = iSize / 2 - 1; i >= 0; --i){
        keepHeap(p, i, iSize);
    }
}
template<typename T>
void heapSort(T *p, int iSize){
    if (NULL == p || 2 > iSize){
        return;
    }
    buildHeap(p, iSize);
    for (int i = iSize - 1; i > 0; --i){
        swapF(p[0], p[i]);
        keepHeap(p, 0, i);
    }
}

template<typename T>
void quickSort(T *a,int left, int right)
{
    int i, j, t, temp;
    if (left>right)
        return;

    temp = a[left]; //temp中存的就是基准数 
    i = left;
    j = right;
    while (i != j)
    {
        //顺序很重要，要先从右边开始找 
        while (a[j] >= temp && i<j)
            j--;
        //再找右边的 
        while (a[i] <= temp && i<j)
            i++;
        //交换两个数在数组中的位置 
        if (i<j)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    //最终将基准数归位 
    a[left] = a[i];
    a[i] = temp;

    //i = left, j = right - 1;
    //int key = a[right];

    //T tt;
    //while (i < j){
    //    if (a[i] < key){
    //        ++i;
    //    }
    //    else{
    //        tt = a[i], a[i] = a[j], a[j] = tt;
    //        --j;
    //    }
    //}

    //a[right] = a[i], a[i] = key;
    quickSort(a, left, i - 1);//继续处理左边的，这里是一个递归的过程 
    quickSort(a, i + 1, right);//继续处理右边的 ，这里是一个递归的过程 
}

#endif