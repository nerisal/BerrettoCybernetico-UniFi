//
// Created on: 13/mar/2018
// Author: bertini
//

#include "Weapon.h"

Weapon::Weapon(int s, bool m) : strength(s), magic(m) {
}

Weapon::Weapon() : Weapon(10, false) {
}

Weapon::~Weapon() {

}


int Weapon::use() {
    int result = strength;
    if (magic)
        result *= 2;
    return result;
}