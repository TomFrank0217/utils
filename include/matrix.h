#ifndef _MATRIX_H
#define _MATRIX_H

#include "constVal.h"
#include "debugPrint.h"
#include "stdio.h"
#include "string.h"//for memcpy
class matrix
{
public:
    matrix();
    matrix(int iRow, int iCol, DATA_TYPE maxVal);
    matrix(int iHeight, int iWidth, DATA_TYPE *pData = NULL);
    matrix(const matrix &other);
    ~matrix();

    matrix& operator=(const matrix &other);
    matrix operator+(const matrix &other);
    matrix operator-(const matrix &other);
    matrix operator*(const matrix &other);
    matrix operator*(DATA_TYPE scale);
    matrix operator/(DATA_TYPE divisor);
    matrix operator+=(const matrix &other);
    matrix transpose();
    matrix rot180();
    void setHeightAndWidth(int iHeight, int iWidth);
    matrix conv(const matrix &kenerl, int iStride = 1, int iPaddingType = VALID_PADDING);
    void setNewImg(const matrix &SrcImg, const matrix &dstImg);
    void convCompute(const matrix &A, const matrix &kernel, matrix &result, int iStride);
    void conv(const matrix &kernel, const matrix& result, int iStride = 1, int iPaddingType = VALID_PADDING);
    bool checkMatrix(const matrix &A);
    void show();
    friend matrix operator*(DATA_TYPE scale, const matrix &other);
    static int iMatrixCount;
public:
    DATA_TYPE *m_pData;
    int m_iHeight;
    int m_iWidth;
    int m_iSize;
};
#endif
