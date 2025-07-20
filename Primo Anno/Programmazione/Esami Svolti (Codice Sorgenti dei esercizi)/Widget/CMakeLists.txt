cmake_minimum_required(VERSION 3.9)
project(Widget)

set(CMAKE_CXX_STANDARD 11)

add_executable(Widget main.cpp header.h Widget.h Button.h TextArea.h LayoutManager.h)