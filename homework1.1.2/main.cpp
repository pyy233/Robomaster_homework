#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <assert.h>
using namespace cv;
using namespace std;
/*
void onChangeTrackBar(int pos, void* userdata){
    Mat result;
    Mat src=*(Mat*)(userdata);
    medianBlur(src, result, 2*pos-1);
    imshow("apple_detection",result);
    

}
*/
//绘画函数
void dfs(cv::Mat &drawer,
        const std::vector< std::vector<cv::Point> > &contours,
        const std::vector< cv::Vec4i > &hierachy,
        const int &id,
        const int &depth)
{
    if (id == -1){
        return;
    }
    Rect rectang;
    drawContours(drawer, contours, id, {225,225,225}, 3);//画轮廓
    rectang=boundingRect(contours[id]);//轮廓的最小外接方形
    rectangle(drawer, rectang, {225,225,225}, 3, LINE_8);//画方形
}


int main()
{
	Mat apple_image;                                        //原图像
    Mat apple_channels[3];                                  //用于储存三通道
    Mat red_sub_green;                                      //红减绿灰度图
    Mat normal;                                             //归一化后所得图
    Mat binary;                                             //二值化所得图
    Mat blured_img1;                                        //中值滤波处理后图像
    Mat dilated_img;                                        //膨胀后图像
    Mat eroded_img;                                         //腐蚀后图像
    Mat blured_img2;                                        //闭运算后再次使用中值滤波所得图像
    apple_image=cv::imread("../apple.png");                 //读取图像
    assert(apple_image.channels() == 3);                    //检测是否为三通道彩色图片
    split(apple_image, apple_channels);                     //三通道分离
    red_sub_green=apple_channels[2]-apple_channels[1]-apple_channels[0];      //红绿通道相减
    normalize(red_sub_green, normal, 0., 255., cv::NORM_MINMAX);        //归一化
    threshold(normal, binary, 20, 255, THRESH_BINARY);                  //二值化
    medianBlur(binary, blured_img1,7);                                //中值滤波
    Mat dilate_kernel = getStructuringElement(MORPH_RECT,Size(7,7), Point(-1, -1)); //膨胀核
    Mat erode_kernel = getStructuringElement(MORPH_RECT,Size(7,7), Point(-1, -1));  //腐蚀核
    dilate(blured_img1, dilated_img, dilate_kernel,Point(-1, -1),1,0,morphologyDefaultBorderValue());//膨胀
    erode(dilated_img, eroded_img, erode_kernel,Point(-1, -1),1,0,morphologyDefaultBorderValue());//腐蚀
    medianBlur(eroded_img, blured_img2, 7);//中值滤波
    vector< vector<cv::Point> > contour;//轮廓
    vector< Vec4i > hierachy;
    findContours(blured_img2,contour, hierachy, RETR_EXTERNAL, CHAIN_APPROX_NONE);//读取轮廓
    Mat drawer = Mat::zeros(Size(blured_img2.cols, blured_img2.rows), CV_8UC3);//画布
    drawer=apple_image.clone();//复制原始图像
    for (int i = 0; i + 1; i = hierachy[i][0]){
        dfs(drawer, contour, hierachy, i, 0); // 遍历所有轮廓
    }
    imshow("red",binary);
    imshow("contours", drawer);
    //imwrite("../",drawer);

    
    waitKey(0);
	return 0;
}