#ifndef _CONST_VAL_H
#define _CONST_VAL_H

#define DATA_TYPE float

#define NOT_ALL_CONNNECTED 0
#define ALL_CONNECTED      1

#define CONVOLUTION_LAYER       0
#define POOLING_LAYER           1
#define FULL_CONNECTION_LAYER   2
#define INPUT_DATA_LAYER        3

#define MAX_POOLING 0
#define AVE_POOLING 1

#define VALID_PADDING 0
#define SAME_PADDING  1
#define FULL_PADDING  2

#define SEPARATE_NUM -1

#define FREE_BUFFER(pBuffer) \
do{\
    if(NULL!=pBuffer)\
    {\
        delete[] pBuffer;\
        pBuffer=NULL;\
    }\
}while(0)

#endif
