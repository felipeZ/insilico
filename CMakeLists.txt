# Specify the minimum version for CMake

cmake_minimum_required(VERSION 3.0.2)

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

# search for armadillo
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
MESSAGE (STATUS "ARMADILLO PATH:" ${ARMADILLO_LIBRARIES})

# search for HDF5
find_package(HDF5 COMPONENTS CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})
message (STATUS "HDF5 PATH:" ${HDF5_LIBRARIES})

# headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Scan these folders
# add_subdirectory(include)
# add_subdirectory(armadillo)
add_subdirectory(src)
