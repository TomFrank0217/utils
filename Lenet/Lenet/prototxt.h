#ifndef _PROTOTXT_H
#define _PROTOTXT_H
#include <stdio.h>
#include "constVal.h"

typedef struct LayerParams
{
    int iLayerType;

    /* conv ����� */
    int iIfAllConnected;
    int iChannelNum;
    int iHeight;
    int iWidth;
    int iOutputNum;
    int iStride;
    int *piConnected;

    /* padding �ػ��� */
    int iPoolingType;
    int iKernelHeight;
    int iKernelWidth;

    /* fullConnection ȫ���Ӳ� */
}LayerParams;

extern LayerParams layerParams[7];
extern int iLayerNum;
#endif