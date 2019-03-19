# Specify the minimum version for CMake
cmake_minimum_required(VERSION 3.5)

# Project's name
project(insilico LANGUAGES CXX 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compile with optimization by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Required Libraries
find_package(OpenMP REQUIRED)
find_package(Eigen3 3.3 REQUIRED CONFIG)
find_package(range-v3 REQUIRED)

add_subdirectory(src)
