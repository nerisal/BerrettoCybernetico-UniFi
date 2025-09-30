cmake_minimum_required(VERSION 3.31)
project(Esercizio4)

set(CMAKE_CXX_STANDARD 20)

add_executable(Esercizio4 main.cpp LinuxDirectory.cpp LinuxFactory.cpp LinuxFile.cpp LinuxPermission.cpp WindowsDirectory.cpp WindowsFactory.cpp WindowsFile.cpp WindowsPermission.cpp MacOSDirectory.cpp MacOsFactory.cpp MacOSFile.cpp MacOSPermission.cpp)
