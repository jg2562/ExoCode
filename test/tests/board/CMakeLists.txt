cmake_minimum_required(VERSION 2.6)
project(test_board)
add_compile_options(-std=c++11)

file(GLOB SOURCES "*.cpp")

find_package(biomech_exo)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Link test executable against gtest & gtest_main

add_executable(test_board testBoard.cpp)
target_link_libraries(test_board gtest gtest_main biomech_exo)
gtest_add_tests(test_board "" AUTO)
