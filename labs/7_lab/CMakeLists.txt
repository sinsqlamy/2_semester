cmake_minimum_required(VERSION 3.24)
project(7_lab)

set(CMAKE_CXX_STANDARD 17)

include_directories("inc/")

add_executable(7_lab main.cpp inc/shape.h)
