
#
# add_test ... Define test for CTest
# https://cmake.org/cmake/help/latest/command/add_test.html
#
# "If <command> specifies an executable target created by add_executable, it
#  will automatically be replaced by the location of the executable created at
#  at build time."
#
# Build the project first, then go to build directory and execute the 
# following command:
#
# $ctest .
#
# for cmake >= 3.20, you can use --test-dir
# $ctest --test-dir <build_src>
# 
# Visual Studio users should use this command:
# $ctest --test-dir <build_src> -C Debug
#
add_test(NAME api_test COMMAND api_test)

add_executable(api_test)

target_sources(api_test PRIVATE
    harness.c
    main.c
)

target_link_libraries(api_test PRIVATE hello)