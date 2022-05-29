cmake_minimum_required(VERSION 3.13)

project(hello_world VERSION 1.0.0)

option(BUILD_TEST "build test" ON)
option(ENABLE_COVERAGE "build with coverage (unix only)" OFF)

# No IN-SOURCE-BUILD
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source build is disallowed. use \"cmake -B build\"")
endif()    

if (ENABLE_COVERAGE)
  add_compile_options(-fprofile-arcs -ftest-coverage)
  add_compile_options(--coverage)
  link_libraries(gcov)
endif()

add_subdirectory(src)



if (BUILD_TEST)
  # Must explicitly enable testing to use CTest
  enable_testing()
  add_subdirectory(test)
endif()