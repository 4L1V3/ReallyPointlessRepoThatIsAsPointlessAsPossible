cmake_minimum_required(VERSION 3.9)
project(KillProcess)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++")

add_executable(KillProcess main.cpp)
