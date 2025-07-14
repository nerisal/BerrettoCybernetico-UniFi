cmake_minimum_required(VERSION 3.10)
project(Abstract)

set(CMAKE_CXX_STANDARD 11)

add_executable(Abstract main.cpp GameCharacter.h AbstractFactory.h GameCharacterFactory.h JediKnight.h LaserSword.h ProduceFactory.h RebelGuard.h StormTrooper.h Weapon.h WeaponFactory.h Blaster.h)