cmake_minimum_required(VERSION 3.13)

project(hello_world VERSION 1.0.0)

option(BUILD_TEST "build test" ON)

# No IN-SOURCE-BUILD
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source build is disallowed. use \"cmake -B build\"")
endif()    

add_subdirectory(src)

if (BUILD_TEST)
  # Must explicitly enable testing to use CTest
  enable_testing()
  add_subdirectory(test)
endif()