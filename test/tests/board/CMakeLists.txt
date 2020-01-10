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

add_executable(${PROJECT_NAME} testBoard.cpp)
target_link_libraries(${PROJECT_NAME} gtest gtest_main biomech_exo
  mock_ports_input mock_ports_output mock_ports_special)
gtest_add_tests(${PROJECT_NAME} "" AUTO)
