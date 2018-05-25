#ifndef _LAYER_H
#define _LAYER_H

#include "debugPrint.h"
#include "matrix.h"
#include "prototxt.h"

class layer
{
public:
    layer();
    layer(LayerParams *pLayerParams, int iHeight, int iWidth);
    ~layer();
public:
    int m_iChannelNum;
    int m_iDataHeight;
    int m_iDataWidth;
    int m_iOutputNum;
    int m_iKernelHeight;
    int m_iKernelWidth;

    matrix *m_pKernelMatrix;
    matrix *m_pKernelPartialMatrix;
    matrix *m_pDataMatrix;
    matrix *m_pDataPartialMatrix;
    matrix *m_pBias;
    matrix *m_pBiasPartial;
};
#endif
