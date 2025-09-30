//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_LASERSWORD_H
#define ABSTRACT_LASERSWORD_H


#include <iostream>
#include "GameCharacter.h"
#include "Weapon.h"


class LaserSword : public Weapon{
public:
    LaserSword(int strength=6, bool shield=false) : Weapon(strength, shield){}
    virtual int use() override{
        std::cout << "Using laser sword." << std::endl;
    }
};

#endif //ABSTRACT_LASERSWORD_H
