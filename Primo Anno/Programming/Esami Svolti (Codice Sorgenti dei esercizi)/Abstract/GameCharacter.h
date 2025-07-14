//
// Created by m3ta on 7/4/2018.
//

#ifndef ABSTRACT_GAMECHARACTER_H
#define ABSTRACT_GAMECHARACTER_H


//#include "Weapon.h"

#include "Weapon.h"

class GameCharacter{
public:
    GameCharacter(std::string name="", Weapon* weapon= nullptr) : _weapon(weapon), _name(name){}
    virtual int fight(GameCharacter& enemy) = 0;
    virtual void move(int x, int y) = 0;

    const std::string &get_name() const {
        return _name;
    }
private:
    std::string _name;
    Weapon* _weapon;
    int _posX, _posY;

};



#endif //ABSTRACT_GAMECHARACTER_H
