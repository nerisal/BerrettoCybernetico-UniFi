//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_WEAPON_H
#define ABSTRACT_WEAPON_H


//#include "GameCharacter.h"

#include "GameCharacter.h"

class Weapon{
public:
    Weapon(int st=0, bool sh=false) : _strength(st), _shield(sh){}
    virtual int use() = 0;

    int get_strength() const {
        return _strength;
    }

    void set_strength(int _strength) {
        Weapon::_strength = _strength;
    }

    int get_shield() const {
        return _shield;
    }

    void set_shield(int _shield) {
        Weapon::_shield = _shield;
    }

private:
    int _strength, _shield;
};


#endif //ABSTRACT_WEAPON_H
