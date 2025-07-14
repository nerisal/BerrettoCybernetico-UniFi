//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_REBELGUARD_H
#define ABSTRACT_REBELGUARD_H


#include <iostream>
#include "GameCharacter.h"
#include "Blaster.h"

class RebelGuard : public GameCharacter{
public:
    RebelGuard(std::string name = "", Weapon* weapon = nullptr) : GameCharacter(name,blaster){}
    virtual int fight(GameCharacter& enemy) override{
        std::cout << "Rebel guard is fightinh with " <<  enemy.get_name() << std::endl;
    }
    virtual void move(int x, int y) override{
        std::cout << "Rebel guard moves by x: " << x << " y: " << y << std::endl;
    }

private:
    Blaster* blaster;
};

#endif //ABSTRACT_REBELGUARD_H
