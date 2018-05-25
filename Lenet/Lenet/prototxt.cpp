#include "prototxt.h"



//int iArrConnected[] = {
//    /* 1*/0, 1, 2, SEPARATE_NUM,/* 2*/1, 2, 3, SEPARATE_NUM,/* 3*/2, 3, 4, SEPARATE_NUM,/* 4*/3,4,5,SEPARATE_NUM,
//    /* 5*/0, 4, 5, SEPARATE_NUM,/* 6*/0, 1, 5, SEPARATE_NUM,/* 7*/0, 1, 2, 3, SEPARATE_NUM,/* 8*/1,2,3,4,SEPARATE_NUM,
//    /* 9*/ 2, 3, 4, 5, SEPARATE_NUM,/*10*/0, 3, 4, 5, SEPARATE_NUM,/*11*/ 0, 1, 4, 5, SEPARATE_NUM,/* 12*/0,1,2,5,SEPARATE_NUM
//};
LayerParams layerParams[] = {
    //{
    //    INPUT_DATA_LAYER,
    //    1,
    //    0,
    //    0,
    //    1,
    //    1,
    //    NULL,

    //    /* padding 池化层 */
    //    0,//int iPoolingType;
    //    0,//int iKernelHeight;
    //    0,//int iKernelWidth;
    //},

    {//1
        CONVOLUTION_LAYER,//int iLayerType;

        /* conv 卷积层 */
        ALL_CONNECTED,//int iIfAllConnected;
        1,//int iChannelNum;
        5,//int iHeight;
        5,//int iWidth;
        6,//int iOutputNum;
        1,//int iStride;
        NULL,//int *piConnected;

        /* padding 池化层 */
        0,//int iPoolingType;
        0,//int iKernelHeight;
        0,//int iKernelWidth;

        /* fullConnection 全连接层 */
    },

    {//2
        POOLING_LAYER,//int iLayerType;

        /* conv 卷积层 */
        NOT_ALL_CONNNECTED,//int iIfAllConnected;
        0,//int iChannelNum;
        0,//int iHeight;
        0,//int iWidth;
        0,//int iOutputNum;
        0,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        AVE_POOLING,//int iPoolingType;
        2,//int iKernelHeight;
        2,//int iKernelWidth;

        /* fullConnection 全连接层 */
    },

    {//3
        CONVOLUTION_LAYER,//int iLayerType;

        /* conv 卷积层 */
        NOT_ALL_CONNNECTED,//int iIfAllConnected;
        6,//int iChannelNum;
        5,//int iHeight;
        5,//int iWidth;
        16,//int iOutputNum;
        1,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        0,//int iPoolingType;
        0,//int iKernelHeight;
        0,//int iKernelWidth;

        /* fullConnection 全连接层 */
    },

    {//4
        POOLING_LAYER,//int iLayerType;

        /* conv 卷积层 */
        ALL_CONNECTED,//int iIfAllConnected;
        0,//int iChannelNum;
        0,//int iHeight;
        0,//int iWidth;
        0,//int iOutputNum;
        0,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        AVE_POOLING,//int iPoolingType;
        2,//int iKernelHeight;
        2,//int iKernelWidth;
    },

    {//5
        POOLING_LAYER,//int iLayerType;

        /* conv 卷积层 */
        ALL_CONNECTED,//int iIfAllConnected;
        16,//int iChannelNum;
        5,//int iHeight;
        5,//int iWidth;
        120,//int iOutputNum;
        1,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        AVE_POOLING,//int iPoolingType;
        0,//int iKernelHeight;
        0,//int iKernelWidth;
    },

    {//6
        FULL_CONNECTION_LAYER,//int iLayerType;

        /* conv 卷积层 */
        ALL_CONNECTED,//int iIfAllConnected;
        120,//int iChannelNum;
        0,//int iHeight;
        0,//int iWidth;
        84,//int iOutputNum;
        1,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        AVE_POOLING,//int iPoolingType;
        0,//int iKernelHeight;
        0,//int iKernelWidth;
    },

    {//7
        FULL_CONNECTION_LAYER,//int iLayerType;

        /* conv 卷积层 */
        ALL_CONNECTED,//int iIfAllConnected;
        84,//int iChannelNum;
        0,//int iHeight;
        0,//int iWidth;
        10,//int iOutputNum;
        1,//int iStride;
        NULL,//int *piConnected;

        /* pooling 池化层 */
        AVE_POOLING,//int iPoolingType;
        0,//int iKernelHeight;
        0,//int iKernelWidth;
    }
};

int iLayerNum = sizeof(layerParams) / sizeof(layerParams[0]);
