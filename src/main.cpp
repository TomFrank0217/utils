#include "setRandArr.h"
#include <iostream>

#include "printArr.h"
using namespace std;
int main(){
     
    const int iSize = 100;
    int *p = new int[iSize];
    //template<typename T>
    //void setRandVal(T *p, int iSize, T maxVal)
    setRandArr(p, iSize, 100);
    printArr(p, iSize);
	cout<<endl;
    return 0;
}