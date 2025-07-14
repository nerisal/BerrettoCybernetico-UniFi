//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_ABSTRACTFACTORY_H
#define ABSTRACT_ABSTRACTFACTORY_H

#include <string>
#include "GameCharacter.h"
#include "Weapon.h"
#include "ProduceFactory.h"

class AbstractFactory{
public:
    virtual GameCharacter* createCharacter(std::string charType) = 0;
    virtual Weapon* createWeapon(std::string weaponType) = 0;
};

#endif //ABSTRACT_ABSTRACTFACTORY_H
