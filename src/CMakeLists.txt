# headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add compiler flags
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

# create binary
set(SOURCES main.cc funtools.cc)
add_executable(main ${SOURCES})

# Linking
set( CMAKE_VERBOSE_MAKEFILE on )
target_link_libraries(main)

# target_link_libraries(linear_algebra
#   PUBLIC
#     Eigen3::Eigen
#     OpenMP::OpenMP_CXX
#   )
