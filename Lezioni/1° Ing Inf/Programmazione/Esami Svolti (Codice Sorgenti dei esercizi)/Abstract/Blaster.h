//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_BLASTER_H
#define ABSTRACT_BLASTER_H


#include <iostream>
#include "Weapon.h"

class Blaster : public Weapon {
public:
    Blaster(int strength=0, bool shield= false) : Weapon(6,false){}
    virtual int use() override {
        std::cout << "Using blaster" << std::endl;
    }
private:
};


#endif //ABSTRACT_BLASTER_H
