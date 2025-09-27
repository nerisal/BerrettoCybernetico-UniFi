cmake_minimum_required(VERSION 3.31)
project(Esercizio6)

set(CMAKE_CXX_STANDARD 20)

add_executable(Esercizio6 main.cpp CompressionManager.cpp RARCompressor.cpp ZIPCompressor.cpp GZIPCompressor.cpp)
