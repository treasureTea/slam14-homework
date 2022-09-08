#include<iostream>
#include<eigen3/Eigen/Dense>
#include<cmath>

using namespace std;
using namespace Eigen;

int main(int argc, char const *argv[])
{
    Quaterniond q1(0.55,0.3,0.2,0.2);
    Quaterniond q2(-0.1,0.3,-0.7,0.2);

    q1.normalize();
    q2.normalize();

    Vector3d t1(0.7,1.1,0.2);
    Vector3d t2(-0.1,0.4,0.8);

    Isometry3d T1=Isometry3d::Identity();
    T1.rotate(q1);
    T1.pretranslate(t1);

    Isometry3d T2=Isometry3d::Identity();
    T2.rotate(q2);
    T2.pretranslate(t2);

    Vector3d P1(0.5,-0.1,0.2);

    Vector3d P2=T2*T1.inverse()*P1;

    cout<<"P2:"<<P2.transpose()<<endl;

    return 0;
}


