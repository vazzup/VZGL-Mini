# Minimum Cmake version
cmake_minimum_required(VERSION 2.6)

###################################################
# PROJECT Configuration
###################################################
# Project's name
project(VZGL-Mini)
# Set Folder for storing Binaries
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
# Set Folder for storing Executables
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# Set Folder for storing Libraries
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/libs)
# Add Folder with Header Files
include_directories(${CMAKE_SOURCE_DIR}/include)
# Turn on Optimised debugging for gdb
set(CMAKE_BUILD_TYPE RelWithDebInfo)

#####################################################
# Renderer Configuration
#####################################################
# Build the program
add_executable(CameraProcess src/maincamera.cpp src/lanedetection.cpp)
# Link Camera Executable to OpenCV Libs
target_link_libraries(CameraProcess ${OpenCV_LIBS})
