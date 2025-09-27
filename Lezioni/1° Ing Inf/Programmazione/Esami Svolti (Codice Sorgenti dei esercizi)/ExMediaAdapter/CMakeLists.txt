cmake_minimum_required(VERSION 3.10)
project(ExMediaAdapter)

set(CMAKE_CXX_STANDARD 11)

add_executable(ExMediaAdapter main.cpp AdvancedMediaPlayer.h H264Player.h MediaAdapter.h MediaPlayer.h VideoPlayer.h WMVPlayer.h)