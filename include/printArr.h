#ifndef _PRINT_ARR_H
#define _PRINT_ARR_H

#include <iostream>

template<typename T>
void printArr(T *arr,const int iSize){
	if(NULL==arr)
		return;
	for(int i=0;i<iSize;++i){
		std::cout<<arr[i]<<"  ";
	}

	std::cout<<std::endl;
}

#endif