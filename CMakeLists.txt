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

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

# headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Scan these folders
# add_subdirectory(include)
# add_subdirectory(armadillo)
# add_subdirectory(src)


# search for armadillo
find_package(Armadillo REQUIRED)
include_directories(${ARMADILLO_INCLUDE_DIRS})
MESSAGE (STATUS "ARMADILLO PATH:" ${ARMADILLO_LIBRARIES})

# search for HDF5
find_package(HDF5 REQUIRED)
include_directories(${HDF5_INCLUDE_DIRS})
MESSAGE (STATUS "HDF5 PATH:" ${HDF5_LIBRARIES})

# Add armadillo as third party
set(ARMADILLO_PREFIX armadillo850)
set(ARMADILLO_URL ${CMAKE_CURRENT_DIR})
# ExternalProject_Add(
#   URL ${ARMADILLO_URL}
#   PREFIX ${ARMADILLO_PREFIX}
#   CONFIGURE_COMMAND ""
#   )

# create binary
set(SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp ${PROJECT_SOURCE_DIR}/include/gaussFunctions.h)
add_executable(main ${SOURCES})

# Compiler standard
set_property(TARGET main PROPERTY CXX_STANDARD 17)


# Linking
target_link_libraries(main ${ARMADILLO_LIBRARIES})
