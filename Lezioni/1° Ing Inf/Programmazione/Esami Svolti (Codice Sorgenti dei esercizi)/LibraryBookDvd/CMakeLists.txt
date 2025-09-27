cmake_minimum_required(VERSION 3.13)
project(LibraryBookDvd)

set(CMAKE_CXX_STANDARD 17)

add_executable(LibraryBookDvd main.cpp Book.h headers.h Dvd.h Library.h)