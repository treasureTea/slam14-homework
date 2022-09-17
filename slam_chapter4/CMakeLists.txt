cmake_minimum_required( VERSION 2.8 )
project(usingSophus)

find_package(Sophus REQUIRED)
INCLUDE_DIRECTORIES(${Sophus_INCLUDE_DIRS})

add_executable(useSophus main.cpp)
target_link_libraries(useSophus ${Sophus_LIBRARIES})
