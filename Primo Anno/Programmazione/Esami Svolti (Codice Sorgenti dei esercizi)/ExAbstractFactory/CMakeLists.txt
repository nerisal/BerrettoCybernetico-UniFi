cmake_minimum_required(VERSION 3.10)
project(ExAbstractFactory)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExAbstractFactory main.cpp AbstractFactory.h Button.h ButtonSmartphone.h ButtonTablet.h Panel.h PanelSmartphone.h PanelTablet.h Smartphone.h Tablet.h)