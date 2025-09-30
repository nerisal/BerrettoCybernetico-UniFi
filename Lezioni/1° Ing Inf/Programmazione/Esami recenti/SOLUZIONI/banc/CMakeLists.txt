cmake_minimum_required(VERSION 3.10)
project(banc)

set(CMAKE_CXX_STANDARD 11)

add_executable(banc main.cpp UserLogin.h UserOTPLogin.h SmartCardReader.h UserSmartCardAdapter.h)