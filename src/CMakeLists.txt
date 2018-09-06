# create binary
set(SOURCES main.cc funtools.cc funtools.cc) # ${PROJECT_SOURCE_DIR}/include/gaussFunctions.h)
add_executable(main ${SOURCES})

# Compiler standard
set_property(TARGET main PROPERTY CXX_STANDARD 17)

# Linking
set( CMAKE_VERBOSE_MAKEFILE on )
message(STATUS "PATH: " ${HDF5_CXX_LIBRARIES})
target_link_libraries(main ${ARMADILLO_LIBRARIES} ${HDF5_CXX_LIBRARIES})
