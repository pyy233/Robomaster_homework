#include<bits/stdc++.h>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Dense>
#include <opencv2/core/core.hpp>
using namespace std;
using namespace Eigen;
using namespace cv;
int main(){
    Mat camera =(Mat_<double>(3,3)<< 1.4142055480888289e+03, 0., 6.5792667877101735e+02, 
                                    0.,1.4137212634286254e+03, 4.0455967287503142e+02,
                                     0., 0., 1. );
    Mat distort =(Mat_<double>(1,5)<< -1.5713532786218060e-01, 3.3883933349759310e-01,7.0103028435554145e-04, -2.9035486504482461e-04,-4.2372708010388316e-01);
    Quaterniond q(-0.0816168, 0.994363, -0.0676645, -0.00122528);
    vector<Point2f> image_pts{{575.508, 282.175},
                            {573.93, 331.819},
                            {764.518, 337.652},
                            {765.729, 286.741}};
    Point3f centre(0,0,0);
    vector<Point3d> PW_BIG{
                                {-0.115, 0.0265, 0.},
                                {-0.115, -0.0265, 0.},
                                {0.115, -0.0265, 0.},
                                {0.115, 0.0265, 0.}};
    for(const Point3f pt:PW_BIG){
        centre+=pt;
    }
    Mat rvec,tvec;
    solvePnP(PW_BIG,image_pts,camera,distort,rvec,tvec);
    Mat rma;
    Rodrigues(rvec, rma);
    MatrixXd rmat = Map<MatrixXd>(rma.ptr<double>(),3,3);
    MatrixXd tmat = Map<MatrixXd>(tvec.ptr<double>(),3,1);
    Vector3d cpt(centre.x,centre.y,centre.z);
    Vector3d obj=q.matrix()*(rmat*cpt+tmat);
    cout<<"("<<obj(0)<<","<<obj(1)<<","<<obj(2)<<")"<<endl;
    return 0;
}