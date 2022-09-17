#include<iostream>
#include<cmath>
#include<Eigen/Geometry>
#include<Eigen/Core>
#include"sophus/so3.h"
#include"sophus/se3.h"

using namespace std;

int main()
{
    Eigen::Matrix3d R=Eigen::AngleAxisd(M_PI/2,Eigen::Vector3d(0,0,1)).toRotationMatrix();

    Sophus::SO3 SO3_R(R);
    Sophus::SO3 SO3_V(0,0,M_PI/2); 
    Eigen::Quaterniond q(R);
    Sophus::SO3 SO3_Q(q);

    cout<<"SO(3) from matrix: "<<SO3_R<<endl;
    cout<<"SO(3) from vector: "<<SO3_V<<endl;
    cout<<"SO(3) from quaternion :"<<SO3_Q<<endl;
    
    return 0;
}