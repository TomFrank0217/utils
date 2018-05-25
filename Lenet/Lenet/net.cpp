#include "net.h"

net::net(LayerParams *pLayerParams, int iLayerNum, int iInputHeight, int iInputWidth, int iChannelNum)
    :m_pLayerParams(pLayerParams), m_iLayerNum(iLayerNum),
    m_iInputHeight(iInputHeight), m_iInputWidth(iInputWidth), m_iInputChannelNum(iChannelNum)
{
    m_pLayer = new layer[iLayerNum];
    int iHeight = iInputHeight, iWidth = iInputWidth;
    for (int i = 0; i < m_iLayerNum; ++i)
    {
        //todo

        iHeight = (iHeight - (pLayerParams + i)->iKernelHeight) / (pLayerParams + i)->iStride + 1;
        iWidth = (iHeight - (pLayerParams + i)->iKernelWidth) / (pLayerParams + i)->iStride + 1;
        layer tmpLayer(pLayerParams + i, iHeight, iWidth);
        *(m_pLayer + i) = tmpLayer;
    }
}


net::~net()
{
    ;//todo
}

void net::putforward()
{
    LayerParams *pLayerParams_1, *pLayerParams_2;
    layer *pLayer1, *pLayer2;
    for (int i = 0; i < iLayerNum; ++i)
    {
        pLayerParams_1 = m_pLayerParams + i - 1;
        pLayerParams_2 = m_pLayerParams + i;
        pLayer2 = m_pLayer + i;
        if (CONVOLUTION_LAYER == pLayerParams_2->iLayerType)
        {
            for (int j = 0; j < pLayerParams_2->iOutputNum; ++j)
            {
                for (int k = 0; k < pLayerParams_2->iChannelNum; ++k)
                {
                    if (0 != i)
                    {
                        pLayer2->m_pDataMatrix[j] += pLayer1->m_pDataMatrix[k].conv(\
                            pLayer2->m_pKernelMatrix[j*(pLayerParams_2->iChannelNum) + k]);
                    }
                    else
                    {
                        //pLayer2->m_pDataMatrix[j] += inputData.conv(\
                        //    pLayer2->m_pKernelMatrix[j*(pLayerParams_2->iChannelNum) + k]);
                    }

                }
            }
        }
        else if (POOLING_LAYER == pLayerParams_2->iLayerType)
        {

        }
    }
}
void net::backforward()
{

}