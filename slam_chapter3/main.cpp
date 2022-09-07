#include<iostream>
#include<eigen3/Eigen/Dense>
using namespace std;
using namespace Eigen;

int main()
{
    Matrix3d rotation_matrix=Matrix3d::Identity();
    AngleAxisd rotate_vector(M_PI/4,Vector3d(0,0,1));//定义旋转向量：绕z轴旋转45度 :旋转向量为列向量，用Vector定义
    rotation_matrix=rotate_vector.toRotationMatrix();//将旋转向量转化为旋转矩阵
    
    //Vector3d euler_angles=rotate_vector.eulerAngles();不太确定能不能把旋转向量转化为欧拉角
    Vector3d euler_angles=rotation_matrix.eulerAngles(2,1,0);//将旋转矩阵转化为欧拉角 :注意指定yaw，pitch，roll顺序  此处为ZYX顺序
    //欧氏变换
    Isometry3d T=Isometry3d::Identity();//为欧氏变换矩阵开辟一块空间
    T.rotate(rotation_matrix);//按rotate_vector旋转
    T.pretranslate(Vector3d(1,3,4));//平移定义为1,3,4 :列向量 用Vector定义
    cout<<"T_matrix=\n"<<T.matrix ()<<endl;
    
    //四元数
    Quaterniond q=Quaterniond(rotate_vector);//四元数旋转向量给四元数赋值，反之亦然
    cout<<"quaternion=\n"<<q.coeffs()<<endl;


    Vector3d v(1,0,0);//被旋转向量
    Vector3d v_ro1=rotate_vector*v;
    Vector3d v_ro2=rotation_matrix*v;
    Vector3d v_ro3=T*v;
    Vector3d v_ro4=q*v;

    cout<<"(1,0,0)经旋转向量变化后\n"<< v_ro1<<endl;
    cout<<"(1,0,0)经旋转矩阵变化后\n"<< v_ro2<<endl;
    cout<<"(1,0,0)经欧氏变换矩阵变化后\n"<< v_ro3.transpose()<<endl;
    cout<<"(1,0,0)经四元数变化后\n"<< v_ro4<<endl;
    return 0;
}