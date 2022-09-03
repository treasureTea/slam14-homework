#include<iostream>
#include<eigen3/Eigen/Dense>
#include<cmath>
#include<eigen3/Eigen/Geometry>

using namespace std;
using namespace Eigen;

int main()
{
    Matrix<double,100,100> A =MatrixXd::Random(100,100);
    Matrix<double,100,1>   B =MatrixXd::Random(100,1);

    auto x=A.colPivHouseholderQr().solve(B);
    cout<<"QR:"<<x<<endl;

    auto y=A.ldlt().solve(B);
    cout<<"Cho:"<<y<<endl;

    system("pause");
    return 0;
}

