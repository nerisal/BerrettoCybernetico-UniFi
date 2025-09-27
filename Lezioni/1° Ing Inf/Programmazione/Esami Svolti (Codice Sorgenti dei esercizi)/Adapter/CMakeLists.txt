cmake_minimum_required(VERSION 3.9)
project(Adapter)

set(CMAKE_CXX_STANDARD 11)

add_executable(Adapter main.cpp MediaPlayer.h AdvancedMediaPlayer.h header.h WMVPlayer.h VideoPlayer.h Adapter.h H246Player.h)