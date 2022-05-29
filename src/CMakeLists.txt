add_library(hello)
target_sources(hello PRIVATE hello.c)
target_include_directories(hello PUBLIC .)
set_target_properties(hello PROPERTIES
    OUTPUT_NAME "libhello")


add_executable(hello_exe)
target_sources(hello_exe PRIVATE main.c)
target_link_libraries(hello_exe PRIVATE hello)
set_target_properties(hello_exe PROPERTIES
    OUTPUT_NAME "hello")