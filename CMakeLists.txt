# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.5)

# Project's name
project(insilico)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compile with optimization by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Required Libraries
find_package(OpenMP REQUIRED)
find_package(Eigen3 3.3 NO_MODULE)

# Manually include eigen
if(NOT EIGEN3_INCLUDE_DIRS)
  message(STATUS "use EIGEN3_INCLUDE_DIRS: /usr/include/eigen3")
  set(EIGEN3_INCLUDE_DIRS /usr/include/eigen3)
endif()
include_directories(${Eigen_INCLUDE_DIR})

# include ranges
find_package(range-v3 REQUIRED)

# Set the output folder where your program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})


message(STATUS "EIGEN Include: " ${EIGEN3_INCLUDE_DIR})

add_subdirectory(src)
