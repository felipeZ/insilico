# headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add testing
if(ENABLE_TESTING)
  add_subdirectory(tests)
endif()

# Add compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O2 -Wall")
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

# create binary
set(SOURCES main.cc funtools.cc funtools.cc)
add_executable(main ${SOURCES})

# Compiler standard
set_property(TARGET main PROPERTY CXX_STANDARD 17)

if(Elemental_LINK_FLAGS)
  set_target_properties(main PROPERTIES LINK_FLAGS ${Elemental_LINK_FLAGS})
endif()

# Linking
set( CMAKE_VERBOSE_MAKEFILE on )
target_link_libraries(main ${ARMADILLO_LIBRARIES} ${HDF5_CXX_LIBRARIES} Eigen3::Eigen ${Elemental_LIBRARIES})
