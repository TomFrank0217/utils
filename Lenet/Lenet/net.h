#ifndef _NET_H
#define _NET_H

#include "layer.h"
#include "matrix.h"
#include "prototxt.h"

class net
{
public:
    net(LayerParams *pLayerParams, int iLayerNum, int iInputHeight, int iInputWidth, int iChannelNum = 1);
    ~net();
    void putforward();
    void backforward();
private:
    LayerParams *m_pLayerParams;
    layer *m_pLayer;
    int m_iLayerNum;
    int m_iInputHeight;
    int m_iInputWidth;
    int m_iInputChannelNum;
};
#endif