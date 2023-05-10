cmake_minimum_required(VERSION 3.20)
project(HomeWork-4.1)
find_package(Catch2 REQUIRED)
add_executable(HomeWork-4.1 4.1.cpp list_class.h list_class.cpp)

add_subdirectory(../../Catch2 Catch2-build)
add_executable(HomeWork-4.1_test test-4.1.cpp list_class.h list_class.cpp)
target_link_libraries(HomeWork-4.1_test PRIVATE Catch2::Catch2)