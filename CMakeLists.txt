cmake_minimum_required(VERSION 2.6) # compatibilités de CMake
project(parser_ply) # nom du projet 

set(CMAKE_BUILD_TYPE debug) # compilation en mode debug
set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++11") # options

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
FILE(GLOB_RECURSE SRC_FILES src/*.cpp)
FILE(GLOB_RECURSE HDR_FILES include/*.h)


ADD_EXECUTABLE(${PROJECT_NAME} ${HDR_FILES} ${SRC_FILES})