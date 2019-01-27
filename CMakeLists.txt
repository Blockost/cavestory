cmake_minimum_required(VERSION 3.13)
project(cavestory)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(cavestory
        src/Graphics.cpp
        src/Graphics.h
        src/main.cpp)
