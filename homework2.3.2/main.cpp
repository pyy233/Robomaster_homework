#include <iostream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>
#include<cmath>
using namespace cv;
using namespace std;
using namespace Eigen;

#define PI acos(-1.0)

int main(){
    Matrix<double, 3, 4> inner_parameter;
    inner_parameter<<400., 0., 190., 0.,
                    0., 400., 160., 0.,
                    0., 0., 1., 0.;
    Vector3d cam_position_origin;
    Quaterniond cam_posture_origin;
    cam_position_origin<<2.,2.,2.;
    cam_posture_origin=Quaterniond{-0.5,0.5,0.5,-0.5};

    Vector3d rotate_center;
    rotate_center<<0.93,3.0,1.43;
    Vector3d center_to_camera_origin=cam_position_origin-rotate_center;
    Quaterniond first_rotate=Quaterniond{cos(PI/4),sin(PI/4),0.,0.};
    Vector3d center_to_camera_start=first_rotate.matrix()*center_to_camera_origin;

    Matrix3d cam_posture_origin_mat=cam_posture_origin.matrix();
    Vector3d center_to_axis_1=first_rotate.matrix()*(cam_position_origin+cam_posture_origin_mat.block(0,0,3,1)-rotate_center);
    Vector3d center_to_axis_2=first_rotate.matrix()*(cam_position_origin+cam_posture_origin_mat.block(0,1,3,1)-rotate_center);
    Vector3d center_to_axis_3=first_rotate.matrix()*(cam_position_origin+cam_posture_origin_mat.block(0,2,3,1)-rotate_center);


    VideoWriter writer("../logo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 20, Size(1280,720),true);

    for(int i=0;i<=100;i++){
        Quaterniond rotate_q=Quaterniond{cos((-PI/400)*i),sin((-PI/400)*i),0.,0.};
        Vector3d center_to_camera_now=rotate_q.matrix()*center_to_camera_start;
        Vector3d camera_pos_now=center_to_camera_now+rotate_center;

        Matrix3d cam_posture_now_mat=Matrix3d::Zero();
        Vector3d center_to_axis_1_now=rotate_q.matrix()*center_to_axis_1;
        Vector3d center_to_axis_2_now=rotate_q.matrix()*center_to_axis_2;
        Vector3d center_to_axis_3_now=rotate_q.matrix()*center_to_axis_3;
        cam_posture_now_mat.block(0,0,3,1)=center_to_axis_1_now+rotate_center-camera_pos_now;
        cam_posture_now_mat.block(0,1,3,1)=center_to_axis_2_now+rotate_center-camera_pos_now;
        cam_posture_now_mat.block(0,2,3,1)=center_to_axis_3_now+rotate_center-camera_pos_now;

        Matrix4d converter = Matrix4d::Zero();
        //Matrix3d q=cam_posture_origin.matrix();
        converter.block(0, 0, 3, 3) =cam_posture_now_mat.inverse().cast<double>();
        converter.block(0, 3, 3, 1) = -cam_posture_now_mat.inverse().cast<double>()*camera_pos_now;
        converter(3,3) = 1;
        Mat drawer=Mat::zeros(720,1280,CV_8UC3);
        int point_sum;        //点总数
        freopen("../points.txt","r",stdin);
        cin>>point_sum;


        for(int i=1;i<=point_sum;i++){
            double x,y,z;
            cin>>x>>y>>z;

            Vector4d point_world(x,y,z,1);
            Vector3d point_camera = inner_parameter*converter*point_world;
            circle(drawer,Point2d(point_camera(0,0)/point_camera(2,0),point_camera(1,0)/point_camera(2,0)),1,Scalar(255,255,255),1);
        }
        writer << drawer;
        imshow("img",drawer);
        char key=waitKey(50);
        if(key=='q'){
            break;
        }
    }
    writer.release();
    waitKey(0);
    }