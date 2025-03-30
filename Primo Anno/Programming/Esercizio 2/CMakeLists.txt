cmake_minimum_required(VERSION 3.9)
project(E2_class_exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dungeon.cpp Dungeon.h GameCharacter.cpp GameCharacter.h Weapon.cpp Weapon.h Dice.h Dice.cpp)
add_executable(E2_class_exercise main.cpp ${SOURCE_FILES})