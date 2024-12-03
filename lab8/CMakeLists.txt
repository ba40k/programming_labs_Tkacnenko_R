cmake_minimum_required(VERSION 3.29)
project(stackForDerevyago)

set(CMAKE_CXX_STANDARD 20)
add_executable(stackForDerevyago main.cpp)
enable_testing()
add_subdirectory(Google_tests)