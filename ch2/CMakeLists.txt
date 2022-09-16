#声明要求的cmake最低版本
cmake_minimum_required(VERSION 2.8)

#声明一个cmake工程
project(HelloSlam)

#添加一个可执行程序
add_executable(hello_slam hello_slam.cpp)
#添加一个库
add_library(hello libHelloSlam.cpp)

