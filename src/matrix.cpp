#include "matrix.h"
#include "setRandVal.h"

int matrix::iMatrixCount = 0;

bool matrix::checkMatrix(const matrix &A)
{
    bool flag = true;
    if (A.m_iHeight < 1 || A.m_iWidth < 1 || A.m_iSize < 1 || NULL == A.m_pData)
    {
        flag = false;
    }
    return flag;
}

matrix::matrix()
{
    m_iHeight = m_iWidth = m_iSize = 0;
    m_pData = NULL;
    ++iMatrixCount;
}

matrix::matrix(int iHeight, int iWidth, DATA_TYPE *pData)
{
    if (iHeight < 1 || iWidth < 1)
    {
        DEBUG_PRINT("matrix::matrix(int iHeight, int iWidth)\n");
    }

    m_iHeight = iHeight;
    m_iWidth = iWidth;
    m_iSize = m_iHeight*m_iWidth;
    m_pData = new DATA_TYPE[m_iSize + 1];
    if (pData)
    {
        memcpy(m_pData, pData, m_iSize*sizeof(DATA_TYPE));
    }
    else
    {
        memset(m_pData, 0, m_iSize*sizeof(DATA_TYPE));
    }
    ++iMatrixCount;
}

matrix::matrix(int iHeight, int iWidth, DATA_TYPE maxVal)
{
    if (iHeight < 1 || iWidth < 1)
    {
        DEBUG_PRINT("matrix::matrix(int iHeight, int iWidth)\n");
    }

    m_iHeight = iHeight;
    m_iWidth = iWidth;
    m_iSize = m_iHeight*m_iWidth;
    m_pData = new DATA_TYPE[m_iSize + 1];
    setRandVal(m_pData, m_iSize, maxVal);
}

matrix::matrix(const matrix &other)
{
    if (NULL == &other || other.m_iHeight < 1 || other.m_iWidth < 1 || other.m_iSize < 1 || NULL == other.m_pData)
    {
        DEBUG_PRINT("matrix::matrix(const matrix &other)\n");
    }

    m_iHeight = other.m_iHeight;
    m_iWidth = other.m_iWidth;
    m_iSize = m_iHeight*m_iWidth;
    m_pData = new DATA_TYPE[m_iSize + 1];
    memcpy(m_pData, other.m_pData, m_iSize*sizeof(DATA_TYPE));
    ++iMatrixCount;
}

matrix::~matrix()
{
    FREE_BUFFER(m_pData);
    --iMatrixCount;
}

matrix& matrix::operator=(const matrix &other)
{
    if (NULL == &other)
    {
        DEBUG_PRINT("matrix& matrix::operator=(const matrix &other)\n");
    }
    if (&other == this)
    {
        return *this;
    }

    FREE_BUFFER(m_pData);
    m_iHeight = other.m_iHeight;
    m_iWidth = other.m_iWidth;
    m_iSize = other.m_iSize;
    m_pData = new DATA_TYPE[m_iSize + 1];
    memcpy(m_pData, other.m_pData, m_iSize*sizeof(DATA_TYPE));
}

matrix matrix::operator+(const matrix &other)
{
    matrix tmpMatrix;
    if (m_iHeight != other.m_iHeight || m_iWidth != other.m_iHeight || m_iSize != other.m_iSize)
    {
        DEBUG_PRINT("matrix matrix::operator+(const matrix &other)\n");
        return tmpMatrix;
    }
    tmpMatrix = other;
    for (int i = 0; i < m_iSize; i++)
    {
        tmpMatrix.m_pData[i] += m_pData[i];
    }

    return tmpMatrix;
}

matrix matrix::operator+=(const matrix &other)
{
    for (int i = 0; i < m_iSize; i++)
    {
        m_pData[i] += other.m_pData[i];
    }

    return *this;
}
matrix matrix::operator-(const matrix &other)
{
    matrix tmpMatrix;
    if (m_iHeight != other.m_iHeight || m_iWidth != other.m_iHeight || m_iSize != other.m_iSize)
    {
        DEBUG_PRINT("matrix matrix::operator+(const matrix &other)\n");
        return tmpMatrix;
    }
    tmpMatrix = *this;
    for (int i = 0; i < m_iSize; i++)
    {
        tmpMatrix.m_pData[i] -= other.m_pData[i];
    }

    return tmpMatrix;
}

matrix matrix::operator*(DATA_TYPE scale)
{
    matrix tmpMatrix;
    if(false==checkMatrix(*this)){
		DEBUG_PRINT("operator*(DATA_TYPE scale)");
		return tmpMatrix;
	}

    tmpMatrix = *this;
    for (:int i = 0; i < m_iSize; i++)
    {
        tmpMatrix.m_pData[i] *= scale;
    }

    return tmpMatrix;
}
matrix matrix::operator*(const matrix &other)
{
    //todo
    matrix tmpMatrix(m_iHeight, other.m_iWidth);

    if (false == checkMatrix(*this) || false == checkMatrix(other) || m_iWidth != other.m_iHeight)
    {
        DEBUG_PRINT("matrix matrix::operator*(const matrix &other)\n");
        return tmpMatrix;
    }
    int m = m_iHeight, n = other.m_iWidth, s = 0;
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = 0; k < m_iWidth; ++k)
            {
                tmpMatrix.m_pData[s] += m_pData[i*m_iWidth + k] * other.m_pData[k*n + j];
            }
            ++s;
        }
    }
    //tmpMatrix.show();
    return tmpMatrix;
}

matrix matrix::operator/(DATA_TYPE divisor)
{
    matrix tmpMatrix;

    tmpMatrix = *this;
    for (:int i = 0; i < m_iSize; i++)
    {
        tmpMatrix.m_pData[i] /= divisor;
    }

    return tmpMatrix;
}

matrix matrix::transpose()
{
    int iHeight = m_iWidth, iWidth = m_iHeight;
    matrix tmpMatrix(iHeight, iWidth);
    int s = -1;
    for (int i = 0; i < iHeight; ++i)
    {
        for (int j = 0; j < iWidth; ++j)
        {
            tmpMatrix.m_pData[++s] = m_pData[j*m_iWidth+i];
        }
    }

    return tmpMatrix;
}

matrix matrix::rot180()
{
    matrix tmpMatrix(m_iHeight, m_iWidth);
    DATA_TYPE *p = m_pData + m_iSize, *q = tmpMatrix.m_pData;
    --q;
    for (int i = 0; i < m_iSize; i++)
    {
        *++q = *--p;
    }

    return tmpMatrix;
}

void matrix::show()
{
    int iCount = -1;
    for (int i = 0; i < m_iHeight; i++)
    {
        for (int j = 0; j < m_iWidth; j++)
        {
            printf("%5.2f  ", m_pData[++iCount]);
        }
        printf("\n");
    }
    printf("\n");
}

matrix operator*(DATA_TYPE scale, const matrix &other)
{
    matrix tmpMatrix(other);
    int n = tmpMatrix.m_iSize;
    for (int i = 0; i < n; i++)
    {
        tmpMatrix.m_pData[i] *= scale;
    }
    //tmpMatrix.show();
    return tmpMatrix;
}

matrix matrix::conv(const matrix &kernel, int iStride, int iPaddingType)
{
    int iPaddingWidth = 0, iPaddingHeight = 0;
    matrix newImg;
    if (VALID_PADDING == iPaddingType)
    {
        iPaddingWidth = 0;
        iPaddingHeight = 0;
    }
    else if (SAME_PADDING == iPaddingType)
    {
        iPaddingWidth = (kernel.m_iWidth - 1) / 2;
        iPaddingHeight = (kernel, m_iHeight - 1) / 2;
        //matrix newImg(m_iHeight + 2 * iPaddingHeight, m_iWidth + 2 * iPaddingWidth);
        newImg.setHeightAndWidth(m_iHeight + 2 * iPaddingHeight, m_iWidth + 2 * iPaddingWidth);
        setNewImg(*this, newImg);
        newImg.show();
    }
    else if (FULL_PADDING == iPaddingType)
    {
        iPaddingWidth = kernel.m_iWidth - 1;
        iPaddingHeight = kernel.m_iHeight - 1;
        //matrix newImg(m_iHeight + 2 * iPaddingHeight, m_iWidth + 2 * iPaddingWidth);
        newImg.setHeightAndWidth(m_iHeight + 2 * iPaddingHeight, m_iWidth + 2 * iPaddingWidth);
        setNewImg(*this, newImg);
        newImg.show();
    }
    else
    {
        DEBUG_PRINT("matrix matrix::conv(const matrix &kenerl, int iStride = 1, int iPaddingType = VALID_PADDING)\n");
    }

    int iResultHeight = (m_iHeight + 2 * iPaddingHeight - kernel.m_iHeight) / iStride + 1;
    int iResultWidth = (m_iWidth + 2 * iPaddingWidth - kernel.m_iWidth) / iStride + 1;
    matrix resultMatrix(iResultHeight, iResultWidth);
    if (VALID_PADDING == iPaddingType)
    {
        convCompute(*this, kernel, resultMatrix, iStride);
    }
    else
    {
        convCompute(newImg, kernel, resultMatrix, iStride);
    }
    return resultMatrix;
}

void matrix::convCompute(const matrix &Img, const matrix &kernel, matrix &result, int iStride)
{
    int kk = 0, ll = 0, s = 0;
    int iResultHeight = result.m_iHeight;
    int iResultWidth = result.m_iWidth;
    int iKernelHeight = kernel.m_iHeight;
    int iKernelWidth = kernel.m_iWidth;
    int  iImgWidth = Img.m_iWidth;
    int iImgHeight = Img.m_iHeight;
    for (int i = 0; i < iResultHeight; ++i)
    {
        for (int j = 0; j < iResultWidth; ++j)
        {
            kk = i*iStride, ll = j*iStride;
            for (int k = 0; k < iKernelHeight; k++, ++kk, ll -= iKernelWidth)
            {
                for (int l = 0; l < iKernelWidth; l++)
                {
                    result.m_pData[s] += kernel.m_pData[k*iKernelWidth + l] * Img.m_pData[kk*iImgWidth + ll++];
                }
            }
            ++s;
        }
    }
}

void matrix::setNewImg(const matrix &SrcImg, const matrix &dstImg)
{
    //todo
    int iPaddingHeight = (dstImg.m_iHeight - SrcImg.m_iHeight) / 2;
    int iPaddingWidth = (dstImg.m_iWidth - SrcImg.m_iWidth) / 2;
    

    int iSrcHeight = SrcImg.m_iHeight;
    int iSrcWidth = SrcImg.m_iWidth;
    int iDstImgWidth = dstImg.m_iWidth;
    int ii = iPaddingHeight, jj = 0;
    int s = -1, t;
    for (int i = 0; i < iSrcHeight; ++i,++ii)
    {
        //jj = iPaddingWidth;
        t = ii*iDstImgWidth + iPaddingWidth - 1;
        for (int j = 0; j < iSrcWidth; ++j)
        {
            //dstImg.m_pData[ii*iDstImgWidth] = SrcImg.m_pData[++s];
            dstImg.m_pData[++t] =SrcImg.m_pData[++s];
        }
    }
}

void matrix::setHeightAndWidth(int iHeight, int iWidth)
{ 
    if (iWidth*iHeight>m_iWidth*m_iHeight)
    {
        FREE_BUFFER(m_pData);
        m_pData = new DATA_TYPE[iWidth*iHeight + 1];
    }
    m_iHeight = iHeight;
    m_iWidth = iWidth;
    m_iSize = m_iWidth*m_iHeight;
    memset(m_pData, 0, m_iSize*sizeof(DATA_TYPE));
}
