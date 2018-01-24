cmake_minimum_required(VERSION 3.7)
project(ShutdownTimer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(ShutdownTimer ${SOURCE_FILES})

target_link_libraries(ShutdownTimer PUBLIC -static-libgcc)
target_link_libraries(ShutdownTimer PUBLIC -static-libstdc++)