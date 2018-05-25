#ifndef _PROTOTXT_H
#define _PROTOTXT_H
#include <stdio.h>
#include "constVal.h"

typedef struct LayerParams
{
    int iLayerType;

    /* conv 卷积层 */
    int iIfAllConnected;
    int iChannelNum;
    int iHeight;
    int iWidth;
    int iOutputNum;
    int iStride;
    int *piConnected;

    /* padding 池化层 */
    int iPoolingType;
    int iKernelHeight;
    int iKernelWidth;

    /* fullConnection 全连接层 */
}LayerParams;

extern LayerParams layerParams[7];
extern int iLayerNum;
#endif