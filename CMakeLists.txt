# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.10)

# Project's name
project(insilico LANGUAGES CXX CUDA)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
# build setup
###############################################################################

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

######################################################################
# compiler tests
# these need ot be done early (before further tests).
#####################################################################

include(CheckCXXCompilerFlag)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
# Compiler flags
###############################################################################

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CXX_FLAGS)
  #release comes with -O3 by default
  set(CMAKE_BUILD_TYPE Release CACHE STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CXX_FLAGS)

###############################################################################
# Dependencies
###############################################################################

# Search for Cuda
find_package(CUDA REQUIRED)

# Eigen
find_package(Eigen3 3.3 REQUIRED CONFIG)

# Manually include eigen
if(NOT EIGEN3_INCLUDE_DIRS)
  message(STATUS "use EIGEN3_INCLUDE_DIRS: /usr/include/eigen3")
  set(EIGEN3_INCLUDE_DIRS /usr/include/eigen3)
endif()

add_subdirectory(src)
