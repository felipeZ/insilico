# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.0.2)

# Project's name
project(insilico)

# required modules
include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)
include(ExternalProject)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CXX_FLAGS)
  #release comes with -O3 by default
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CXX_FLAGS)


# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# search for elemental
find_package(Elemental REQUIRED)
include_directories(${Elemental_INCLUDE_DIRS})
message(STATUS "ELEMENTAL Libraries: " ${Elemental_LIBRARIES})


# search for HDF5
find_package(HDF5 COMPONENTS CXX REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})
message(STATUS "HDF5 PATH: " ${HDF5_CXX_LIBRARIES})

# search for Eigen
find_package (Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})
message(STATUS "EIGEN Include: " ${EIGEN3_INCLUDE_DIR})

# Scan these folders
# add_subdirectory(include)
# add_subdirectory(armadillo)
add_subdirectory(src)
