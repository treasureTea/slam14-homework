#include<iostream>
#include<cmath>
#include<eigen3/Eigen/Dense>
#include<eigen3/Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main()
{
    Quaterniond q1(0.55,0.3,0.2,0.2);
    Quaterniond q2(0.1,0.3,-0.7,0.2);

    q1.normalize();
    q2.normalize();

    Vector3d t1;
    t1<<0.7,1.1,1.2;
    Vector3d t2;
    t2<<-0.1,0.4,0.8;

    Vector3d p_1;
    p_1<<0.5,-0.1,0.2;

    Isometry3d T1=Isometry3d::Identity();
    T1.rotate(q1);                                     
    T1.pretranslate(t1);

    Isometry3d T2=Isometry3d::Identity();
    T1.rotate(q2);                                     
    T1.pretranslate(t2);

    return 0;
}
