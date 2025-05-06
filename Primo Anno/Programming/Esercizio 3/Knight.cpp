//
// Created by Marco Bertini on 08/04/18.
//

#include "Knight.h"

int Knight::fight(GameCharacter& enemy) {
    int damage =  GameCharacter::fight(enemy);
    if (dexterity > 10) {
        damage += GameCharacter::fight(enemy);
    }

    if (paladin) {
        damage += 10;
    }

    return damage;
}

void Knight::move(int x, int y) {
    GameCharacter::move(x, y);
    if (dexterity > 10) {
        GameCharacter::move(x, y);
    }
}

void Knight::setName(const std::string& n) {
    name = n;
}

std::string Knight::getName(){
    return name;
}

void Knight::setDexterity(int d) {
    dexterity = d;
}

int Knight::getDexterity() const {
    return dexterity;
}

void Knight::setPaladin(bool p) {
    paladin = p;
}

bool Knight::isPaladin() const {
    return paladin;
}


