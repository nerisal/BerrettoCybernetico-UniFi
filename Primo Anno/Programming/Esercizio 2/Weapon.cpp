//
// Created on: 13/mar/2018
// Author: bertini
//

#include "Weapon.h"

// In questo caso ho delegato il costruttore di default a quello creato da me
// In questo modo, se creo un oggetto Weapon senza passare dei parametri, avrò
// un'arma non magica con danno 10.
Weapon::Weapon() :Weapon(10, false){}

Weapon::Weapon(const int s,const bool m) : strength(s), magic(m){
}

int Weapon::use() const {
    int result = strength;
    if (magic)
        result *= 2;
    return result;
}
