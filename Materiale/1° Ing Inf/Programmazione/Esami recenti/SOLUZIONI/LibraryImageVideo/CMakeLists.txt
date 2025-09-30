cmake_minimum_required(VERSION 3.10)
project(LibraryImageVideo)

set(CMAKE_CXX_STANDARD 11)

add_executable(LibraryImageVideo main.cpp header.h Video.h Image.h PlayList.h FileAudio.h Audio.h)