//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_WEAPONFACTORY_H
#define ABSTRACT_WEAPONFACTORY_H


#include "AbstractFactory.h"
#include "LaserSword.h"
#include "Blaster.h"

class WeaponFactory : public AbstractFactory{
public:
    virtual GameCharacter* createCharacter(std::string charType) override{}
    virtual Weapon* createWeapon(std::string weaponType) override{
        Weapon* weapon;
        if(weaponType.compare("l") == 0){
            weapon = new LaserSword(0,false);
            std::cout << "Laser sword created." << std::endl;
        }else if(weaponType.compare("b") == 0){
            weapon = new Blaster(0,false);
            std::cout << "Blaster created." << std::endl;
        }else{
            weapon = nullptr;
            std::cout << "No weapon is created." << std::endl;
        }
        return weapon;
    }
};


#endif //ABSTRACT_WEAPONFACTORY_H
