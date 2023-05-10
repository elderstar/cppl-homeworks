cmake_minimum_required(VERSION 3.20)
project(HomeWork-4.2)

find_package(Catch2 REQUIRED)
add_executable(HomeWork-4.2 4.2.cpp list_class.h list_class.cpp)

add_subdirectory(../../Catch2 Catch2-build)
add_executable(HomeWork-4.2_test test-4.2.cpp list_class.h list_class.cpp)
target_link_libraries(HomeWork-4.2_test PRIVATE Catch2::Catch2)