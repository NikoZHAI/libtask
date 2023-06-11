cmake_minimum_required(VERSION 3.02)
project(libtask-tests LANGUAGES CXX)

find_package(GTest REQUIRED)

# Language standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

include(GoogleTest)

enable_testing()

add_executable(test_vanilla test_vanilla.cpp)
target_link_libraries(test_vanilla GTest::gtest_main)

gtest_discover_tests(test_vanilla)
