cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME llab14)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQIRED TRUE)

add_executable("${PROJECT_NAME}" lab14.cpp)