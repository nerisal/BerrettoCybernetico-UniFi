cmake_minimum_required(VERSION 3.10)
project(DocumentElementsLayout)

set(CMAKE_CXX_STANDARD 11)

add_executable(DocumentElementsLayout main.cpp DocumentElement.h header.h TextElement.h ImageElement.h LayoutElement.h)