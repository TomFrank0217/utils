#include <iostream>
//#include "constVal.h"
#include "matrix.h"
#include "prototxt.h"
#include "net.h"
using namespace std;

void test();
int main(int argc, char *argv[])
{
    test();
    return 0;
}
void test()
{
    net netA(layerParams, iLayerNum, 32, 32);
    DATA_TYPE arr[] = { 1, 2, 3, 3, 2, 1, 2, 2, 2 };
    matrix A(3, 3, arr);
    A.show();


}