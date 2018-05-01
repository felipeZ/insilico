# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

# Project's name
project(insilico)

# required modules
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)
include(ExternalProject)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Scan these folders
# add_subdirectory(include)
# add_subdirectory(armadillo)
# add_subdirectory(src)

# create binary
set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/include/gaussFunctions.h)

add_executable(main ${SOURCES})
