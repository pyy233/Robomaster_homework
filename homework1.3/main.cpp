#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <assert.h>
using namespace cv;
using namespace std;
int main(){
    VideoCapture video("../armor.mp4"); 
    Mat src;
    while (video.read(src)) {
        Mat hsv_img;
        cvtColor(src, hsv_img, COLOR_BGR2HSV);
        Mat yellow;
        inRange(hsv_img, Scalar(18, 80, 120), Scalar(34, 255, 255), yellow);
        Mat blured;
        GaussianBlur(yellow, blured, Size(7, 7), 0, 0);
        Mat closed;
        Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
        morphologyEx(blured, closed, MORPH_CLOSE, kernel);
        //imshow("closed",closed);
        vector<vector<Point>> contours;
        vector<vector<Point2f>> lights(4, vector<Point2f>(4));
        int id = 0;
        findContours(closed, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
        for (int i = 0; i < contours.size(); i++) {
            Rect rect = boundingRect(contours[i]);
            if((double(rect.height / rect.width) > 1.2) && (contourArea(contours[i]) > 400)&&(double(rect.height / rect.width) < 2.1)){
                lights[id][0].x = rect.x;
                lights[id][0].y = rect.y;
                lights[id][1].x = rect.x + rect.width;
                lights[id][1].y = rect.y;
                lights[id][2].x = rect.x + rect.width;
                lights[id][2].y = rect.y + rect.height;
                lights[id][3].x = rect.x;
                lights[id][3].y = rect.y + rect.height;
                id++;
            }
            if(id == 4){
                id = 0;
                break;
            }
        }
        for (int i = 0; i < 3; i+=2){
            if((norm(lights[i][0] - lights[i+1][0]) < 80) && ((lights[i][0].y / lights[i+1][0].y) < 1.2 || lights[i][0].y / lights[i+1][0].y > 0.87)){
                line(src, lights[i][0], lights[i+1][1], Scalar(255, 0, 0), 3);
                line(src, lights[i][3], lights[i+1][2], Scalar(255, 0, 0), 3);
                line(src, lights[i][0], lights[i][3], Scalar(255, 0, 0), 3);
                line(src, lights[i+1][1], lights[i+1][2], Scalar(255, 0, 0), 3);
            }
        }
        imshow("Armor_result", src);
        int key = waitKey(10);
        if (key == 'e') break;
    }

    
    return 0;
}