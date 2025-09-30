cmake_minimum_required(VERSION 3.10)
project(Es4Observer)

set(CMAKE_CXX_STANDARD 11)

add_executable(Es4Observer main.cpp Observer.h Subject.h SumFormula.h SumFormula.cpp)