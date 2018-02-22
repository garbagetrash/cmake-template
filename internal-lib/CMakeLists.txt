# Create any internal libraries by setting up a CMakeLists.txt as if they were
# standalone.
cmake_minimum_required(VERSION 3.5.1 FATAL_ERROR)
project(internal-lib VERSION 1.0.0 LANGUAGES C)

add_library(internal-lib STATIC
  src/pc1.c
  )

target_include_directories(internal-lib
  PUBLIC include
  PRIVATE src
  )
