cmake_minimum_required(VERSION 3.21)
project(E0b_compilation_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_executable(E0b_compilation_example main.cpp greeter.cpp greeter.h adder.cpp adder.h)
