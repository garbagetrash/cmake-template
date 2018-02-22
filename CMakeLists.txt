cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(MyApp VERSION 1.0.0 LANGUAGES C)

# Build any internal libraries
add_subdirectory(internal-lib)

# Import any pre-compiled libraries
add_library(precompiled STATIC IMPORTED)
set_property(TARGET precompiled PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/precompiled/lib/libprecompiled.a)

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
