cmake_minimum_required(VERSION 3.13)
project(cavestory)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
set(CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS} -Wall -pedantic -Wextra -Weffc++ -ansi")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(cavestory ${SDL2_INCLUDE_DIRS})
include_directories(cavestory ${SDL2_IMAGE_INCLUDE_DIRS}})
include_directories(src)

add_library(tinyxml2 lib/tinyxml2/tinyxml2.h lib/tinyxml2/tinyxml2.cpp)

add_executable(cavestory
        src/Graphics.cpp
        src/Graphics.h
        src/main.cpp
        src/Game.cpp
        src/Game.h
        src/util/Flags.h
        src/AnimatedSprite.cpp
        src/AnimatedSprite.h
        src/Player.cpp
        src/Player.h
        src/util/Globals.h
        src/Level.cpp
        src/Level.h)

target_link_libraries(cavestory ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})
