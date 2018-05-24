#include "iomanip"
#include "opencv2/opencv.hpp"
#include "io.h"
using namespace cv;
using namespace std;
#include <vector>
#include <algorithm>
//#include <windows.h>
int main(int argc, char *argv[])
{
    //Mat src;
    ////加载图片
    ////src = imread("F://chormeDownload//trainimage//pic2//0//2.bmp", CV_LOAD_IMAGE_COLOR);
    //src = imread("F://chormeDownload//trainimage//pic2//0//2.bmp", CV_LOAD_IMAGE_ANYDEPTH);
    vector<string> vecStr;
    const int n = 10;
    string str2 = "";
    string str3;
    string str = "F:\\chormeDownload\\trainimage\\pic2\\0\\*.bmp";
    string strs[10];
    const char *filenames[n];
    for (int i = 0; i < n; ++i){
        strs[i] = str;
        strs[i][34] = char('0' + i);
        filenames[i] = strs[i].c_str();
    }

    for (int i = 0; i < n; ++i){
        vector<string> vectmp;
        const int len = 1000;
        int iCount = 1;
        //cout << filenames[i] << endl;
        cout << "i=" << i << endl;
        struct _finddata_t fileinfo;
        long handle;
        handle = _findfirst(filenames[i], &fileinfo);
        if (handle == -1)
            cout << "fail..." << endl;
        else{
            str2 = strs[i].substr(0, 36);
            //cout << str2 << endl;
            str3 = str2 + fileinfo.name;
            //cout << str3 << endl;
            vectmp.push_back(str3);
        }
        while (!_findnext(handle, &fileinfo))
        {
            str2 = strs[i].substr(0, 36);
            str3 = str2 + fileinfo.name;
            //cout << str3 << endl;
            vectmp.push_back(str3);
            iCount++;
            if (iCount >= len){
                break;
            }
        }
        vecStr.insert(vecStr.end(), vectmp.begin(), vectmp.end());
        cout << vectmp.size() << "   " << vecStr.size() << endl;
        _findclose(handle);
    }

    random_shuffle(vecStr.begin(), vecStr.end());

    for (int i = 0; i < vecStr.size(); ++i){
        Mat src;
        //加载图片
        cout << vecStr[i] << endl;
        src = imread(vecStr[i], CV_LOAD_IMAGE_ANYDEPTH);
        //检测是否加载成功
        if (!src.data)  //or == if(src.empty())
        {
            cout << "Could not open or find the image" << endl;
            return -1;
        }
        // 创建窗口
        namedWindow("Display", CV_WINDOW_AUTOSIZE);
        //显示图像
        imshow("Display", src);

        cout << src.rows << "  " << src.cols << "  " << src.channels() << endl;
        //暂停，等待按键结束
        int num = 0;
        for (int row = 0; row < src.rows; ++row){
            for (int col = 0; col < src.cols; ++col){
                num = src.at<uchar>(row, col);
                if (0 == num){
                    cout << "  ";
                }
                else{
                    cout << "##";
                }
            }
            cout << endl;
        }
        waitKey(1000);
        int sss = 0;
    }
    
    return 0;
}
