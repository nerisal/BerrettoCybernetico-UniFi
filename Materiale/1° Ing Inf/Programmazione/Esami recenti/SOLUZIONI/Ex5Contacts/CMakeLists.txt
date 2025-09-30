cmake_minimum_required(VERSION 3.10)
project(Ex5Contacts)

set(CMAKE_CXX_STANDARD 11)

add_executable(Ex5Contacts main.cpp Address.h ContactNumber.h Contacts.h Email.h Person.h)