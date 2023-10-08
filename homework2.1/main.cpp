#include <iostream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
using namespace cv;
using namespace std;
using namespace Eigen;

int main(){
    Matrix<double, 3, 4> inner_parameter;
    inner_parameter<<400., 0., 190., 0.,
                    0., 400., 160., 0.,
                    0., 0., 1., 0.;
    Vector3d cam_position;
    Quaterniond cam_posture;
    cam_position<<2.,2.,2.;
    cam_posture=Quaterniond{-0.5,0.5,0.5,-0.5};
    Matrix4d converter = Matrix4d::Zero();
    Matrix3d q=cam_posture.matrix();
    converter.block(0, 0, 3, 3) =q.transpose().cast<double>();
    converter.block(0, 3, 3, 1) = -q.transpose().cast<double>()*cam_position;
    converter(3,3) = 1;
    Mat drawer(1000,2000,CV_8UC3);
    int point_sum;        //点总数
    freopen("../points.txt","r",stdin);
	cin>>point_sum;
    for(int i=1;i<=point_sum;i++){
        double x,y,z;
        cin>>x>>y>>z;
        Vector4d point_world(x,y,z,1);
        //Vector4d c4=converter*point_world;
        Vector3d point_camera = inner_parameter*converter*point_world;
        circle(drawer,Point2d(point_camera(0,0)/point_camera(2,0),point_camera(1,0)/point_camera(2,0)),1,Scalar(255,255,255),1);
    }
    imshow("img",drawer);
    imwrite("../jiaolong.jpg",drawer);
    waitKey(0);
    }