//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_JEDIKNIGHT_H
#define ABSTRACT_JEDIKNIGHT_H

#include <iostream>
#include "GameCharacter.h"
#include "LaserSword.h"

class JediKnight : public GameCharacter{
public:
    JediKnight(std::string name = "Jedi Knight", LaserSword* laserSword = nullptr) : GameCharacter(name,laserSword) {}
    virtual int fight(GameCharacter& enemy) override{
        std::cout << "Jedi knight fights with " << enemy.get_name() << std::endl;
    }
    virtual void move(int x, int y) override{
        std::cout << "Jedi knight moves by x: " << x << " y: " << y << std::endl;
    }

};


#endif //ABSTRACT_JEDIKNIGHT_H
