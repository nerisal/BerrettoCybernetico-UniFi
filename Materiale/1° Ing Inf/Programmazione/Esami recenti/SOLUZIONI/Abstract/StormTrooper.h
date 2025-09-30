//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_STORMTROOPER_H
#define ABSTRACT_STORMTROOPER_H


#include <iostream>
#include "GameCharacter.h"

class StormTrooper : public GameCharacter{
public:
    StormTrooper(std::string name= "", Weapon* weapon = nullptr) : GameCharacter(name,weapon){}
    virtual int fight(GameCharacter& enemy) override{
        std::cout << "Storm trooper fights." << std::endl;
    }
    virtual void move(int x, int y) override{
        std::cout << "Storm trooper moves by x: " << x << " y: " << y << std::endl;
    }
};


#endif //ABSTRACT_STORMTROOPER_H
