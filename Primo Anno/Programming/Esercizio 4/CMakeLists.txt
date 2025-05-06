cmake_minimum_required(VERSION 3.9)
project(E4_abstract_classes_exercise)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Dungeon.cpp Dungeon.h GameCharacter.cpp GameCharacter.h Weapon.cpp Weapon.h Dice.h Dice.cpp Sword.cpp Sword.h Bow.cpp Bow.h Orc.cpp Orc.h Knight.cpp Knight.h Wizard.cpp Wizard.h Skeleton.cpp Skeleton.h MageKnight.cpp MageKnight.h)
add_executable(E4_abstract_classes_exercise main.cpp ${SOURCE_FILES})