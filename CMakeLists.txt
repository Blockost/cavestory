cmake_minimum_required(VERSION 3.13)
project(cavestory)

set(CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
include_directories(cavestory ${SDL2_INCLUDE_DIRS})
include_directories(src)

add_executable(cavestory
        src/Graphics.cpp
        src/Graphics.h
        src/main.cpp
        src/Game.cpp
        src/Game.h)

target_link_libraries(cavestory ${SDL2_LIBRARIES})
