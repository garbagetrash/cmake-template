cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(MyApp VERSION 1.0.0 LANGUAGES C)

# If cross compiling, do stuff a bit differently
set(LIB_CMOCKA libcmocka.a)
set(LIB_PRECOMPILED libprecompiled.a)
if(${CMAKE_CROSSCOMPILING})
  message(STATUS "Cross compiling for aarch64!")
  message(STATUS "Toolchain file: " ${CMAKE_TOOLCHAIN_FILE})
  set(LIB_CMOCKA libcmocka-aarch64.a)
  set(LIB_PRECOMPILED libprecompiled-aarch64.a)
endif(${CMAKE_CROSSCOMPILING})

# Enable tests
enable_testing()

# Build any internal libraries by setting them up in a subdirectory with their
# own CMakeLists.txt so that they can build standalone, then just use the build
# command "add_subdirectory()"
add_subdirectory(internal-lib)

# Import any pre-compiled libraries by using the "add_library()" build command
# with the "IMPORTED" keyword.  Be sure to use the "set_property()" command to
# set the "IMPORTED_LOCATION" to the location of the static library, ensuring
# the absolute path is given.
add_library(precompiled STATIC IMPORTED)
set_property(TARGET precompiled PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/precompiled/lib/${LIB_PRECOMPILED})

# Create app
add_executable(myapp
  src/myapp.c
  )

target_link_libraries(myapp
  PRIVATE internal-lib
  PRIVATE precompiled
  )

target_include_directories(myapp
  PUBLIC include
  PRIVATE ${CMAKE_SOURCE_DIR}/precompiled/include
  )

# CMocka unit tests treated like internal libraries with subdirectory build.
add_subdirectory(test)
