# Need to have CMocka installed, now find it on local machine
find_package(cmocka REQUIRED)

# Test null
add_executable(test_null
  test_null.c
  )
target_link_libraries(test_null
  PRIVATE ${CMOCKA_LIBRARIES}
  )
target_include_directories(test_null
  PRIVATE ${CMOCKA_INCLUDE_DIR}
  )
add_test(test_null test_null)

# Test pc1 library
add_executable(test_pc1
  test_pc1.c
  )
target_link_libraries(test_pc1
  PRIVATE internal-lib
  PRIVATE ${CMOCKA_LIBRARIES}
  )
target_include_directories(test_pc1
  PRIVATE ${CMAKE_SOURCE_DIR}/../internal-lib/include
  PRIVATE ${CMOCKA_INCLUDE_DIR}
  )
add_test(test_pc1 test_pc1)

# Test pc2 library
add_executable(test_pc2
  test_pc2.c
  )
target_link_libraries(test_pc2
  PRIVATE precompiled
  PRIVATE ${CMOCKA_LIBRARIES}
  )
target_include_directories(test_pc2
  PRIVATE ${CMAKE_SOURCE_DIR}/../precompiled/include
  PRIVATE ${CMOCKA_INCLUDE_DIR}
  )
add_test(test_pc2 test_pc2)
