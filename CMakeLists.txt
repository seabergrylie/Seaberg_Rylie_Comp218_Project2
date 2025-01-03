cmake_minimum_required(VERSION 3.29)
project(Seaberg_Rylie_Comp218_Project2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Seaberg_Rylie_Comp218_Project2 main.cpp
        cmake-build-debug/stack.cpp
        cmake-build-debug/stack.h
        cmake-build-debug/doublylinkedlist.cpp
        cmake-build-debug/doublylinkedlist.h
)
