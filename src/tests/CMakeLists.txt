find_package(Boost 1.57 REQUIRED COMPONENTS unit_test_framework)

if(ENABLE_TESTING)
  list(APPEND test_cases test_eigen)
    foreach(PROG ${test_cases} )
    add_executable(unit_${PROG} ${PROG}.cc)
    target_include_directories(unit_${PROG} PRIVATE ${Boost_INCLUDE_DIRS})
    # indicates the shared library variant
    target_compile_definitions(unit_${PROG} PRIVATE "BOOST_TEST_DYN_LINK=1")
    # indicates the link paths
    target_link_libraries(unit_${PROG} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    add_test(NAME unit_${PROG} COMMAND unit_${PROG})

    set_tests_properties(unit_${PROG} PROPERTIES LABELS "insilico")
    
  endforeach(PROG)

endif()
