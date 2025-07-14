cmake_minimum_required(VERSION 3.7)
project(ShoppingItems)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Customer.h header.h Items.h Order.h)
add_executable(ShoppingItems ${SOURCE_FILES})