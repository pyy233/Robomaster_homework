#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <assert.h>
using namespace cv;
using namespace std;
bool judgeContourByArea(const std::vector<cv::Point> &contour)
{
    double rect_area, contour_area, rect_length, contour_length;
    RotatedRect rect = minAreaRect(contour);
    rect_area = rect.size.area();
    contour_area = cv::contourArea(contour);
    if (rect_area < 1.2 * contour_area) // 轮廓面积约束
        return true;

    return false;
}
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
    if(judgeContourByArea(contours[id])==true){
        RotatedRect rectang;
        rectang=minAreaRect(contours[id]);//轮廓的最小外接方形
        Point2f* vertices = new cv::Point2f[4];
	    rectang.points(vertices);
        //逐条边绘制
	    for (int j = 0; j < 4; j++)
	    {
		    line(drawer, vertices[j], vertices[(j + 1) % 4], cv::Scalar(0, 255, 0));
	    }

    }
 
	
}
int main()
{
    Mat src;
    src=imread("../plates/005.jpg");
    assert(src.channels() == 3);
    Mat hsv_img;
    cvtColor(src, hsv_img, COLOR_BGR2HSV);
    Mat hsv_img_blue;
    inRange(hsv_img, Scalar(100, 150, 50), Scalar(120, 255, 255), hsv_img_blue);
    Mat blured_img;
    medianBlur(hsv_img_blue, blured_img, 7);                                //中值滤波
    Mat dilated_img;
    Mat eroded_img;
    Mat dilate_kernel = getStructuringElement(MORPH_RECT,Size(43,43), Point(-1, -1)); //膨胀核
    Mat erode_kernel = getStructuringElement(MORPH_RECT,Size(55,55), Point(-1, -1));  //腐蚀核
    dilate(blured_img, dilated_img, dilate_kernel,Point(-1, -1),1,0,morphologyDefaultBorderValue());//膨胀
    erode(dilated_img, eroded_img, erode_kernel,Point(-1, -1),1,0,morphologyDefaultBorderValue());//腐蚀
    vector< vector<cv::Point> > contour;//轮廓
    vector< Vec4i > hierachy;
    findContours(eroded_img,contour, hierachy, RETR_EXTERNAL, CHAIN_APPROX_NONE);//读取轮廓
    Mat drawer = Mat::zeros(Size(eroded_img.cols, eroded_img.rows), CV_8UC3);//画布
    drawer=src.clone();//复制原始图像
    for (int i = 0; i + 1; i = hierachy[i][0]){
        dfs(drawer, contour, hierachy, i, 0); // 遍历所有轮廓
    }
    imshow("origin",src);
    imshow("blue",blured_img);
    imshow("contours", drawer);
    
    waitKey(0);
}