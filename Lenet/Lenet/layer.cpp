#include "layer.h"

layer::layer()
{
    m_iChannelNum = 0;
    m_iDataHeight = 0;
    m_iDataWidth = 0;
    m_iOutputNum = 0;
    m_iKernelHeight = 0;
    m_iKernelWidth = 0;

    m_pKernelMatrix = NULL;
    m_pKernelPartialMatrix = NULL;
    m_pDataMatrix = NULL;
    m_pDataPartialMatrix = NULL;
    m_pBias = NULL;
    m_pBiasPartial = NULL;
    DEBUG_PRINT("default layer constructor\n");
}

layer::layer(LayerParams *pLayerParams, int iHeight, int iWidth) :
m_iChannelNum(pLayerParams->iChannelNum),
m_iDataHeight(iHeight), m_iDataWidth(iWidth),
m_iOutputNum(pLayerParams->iOutputNum),
m_iKernelHeight(pLayerParams->iKernelHeight), m_iKernelWidth(pLayerParams->iKernelWidth)
{
    m_pKernelMatrix = new matrix[m_iChannelNum*m_iOutputNum];
    m_pKernelPartialMatrix = new matrix[m_iChannelNum*m_iOutputNum];
    m_pDataMatrix = new matrix[m_iOutputNum];
    m_pDataPartialMatrix = new matrix[m_iOutputNum];
    m_pBias = m_pBiasPartial = new matrix(m_iOutputNum, 1);
    if (CONVOLUTION_LAYER == pLayerParams->iLayerType)
    {
        for (int i = 0; i < m_iOutputNum*m_iOutputNum; ++i)
        {
            *(m_pKernelPartialMatrix + i) = *(m_pKernelMatrix + i) = *(new matrix(m_iKernelHeight, m_iKernelWidth));
        }
        for (int i = 0; i < m_iOutputNum; ++i)
        {
            *(m_pDataPartialMatrix + i) = *(m_pDataMatrix + i) = *(new matrix(m_iDataHeight, m_iDataWidth));
        }
    }
    else if (POOLING_LAYER == pLayerParams->iLayerType)
    {
        for (int i = 0; i < m_iOutputNum; ++i)
        {
            *(m_pDataPartialMatrix + i) = *(m_pDataMatrix + i) = *(new matrix(m_iDataHeight, m_iDataWidth));
        }
    }
    else if (FULL_CONNECTION_LAYER == pLayerParams->iLayerType)
    {
        *(m_pKernelPartialMatrix) = *(m_pKernelMatrix) = *(new matrix(m_iOutputNum, m_iChannelNum));
        *(m_pDataMatrix) = *(m_pDataPartialMatrix) = *(new matrix(m_iOutputNum, 1));
    }
}

layer::~layer()
{
    //todo;
    ;
}