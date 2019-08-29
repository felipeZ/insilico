# Add compiler flags
message(STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS})

# create binary
set(SOURCES main.cc insilico.cc kernels.cu)
add_executable(main ${SOURCES})

# Linking
set( CMAKE_VERBOSE_MAKEFILE on )

set_target_properties(main
  PROPERTIES
  # Enforce Standard
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED ON
  # Enable reallocatable device code
  CUDA_SEPARABLE_COMPILATION ON
  )

target_include_directories(main
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
  ${CUDA_INCLUDE_DIRS}
  )

target_link_libraries(main
  PUBLIC
  Eigen3::Eigen
  ${CUDA_LIBRARIES}
  ${CUDA_CUBLAS_LIBRARIES}
  )

# Add testing
if(ENABLE_TESTING)
  add_subdirectory(tests)
endif()
