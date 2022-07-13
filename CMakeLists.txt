cmake_minimum_required(VERSION 3.18)
project(GraphData)

set(CMAKE_CXX_STANDARD 20)

add_executable(GraphData main.cpp DataInputAndOutput.h DataConverter.h GraphMethods.h DataConverter.cpp DataInputAndOutput.cpp GraphStruct.cpp)
