/*
 * Character.cpp
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#include "GameCharacter.h"

#include <ctime>
#include <iostream>

using namespace std;

GameCharacter::GameCharacter() : GameCharacter(10, 10){}
GameCharacter::GameCharacter(const int hp,const int a) : HP(hp), armor(a), posX(0), posY(0), weapon(nullptr){}
GameCharacter::~GameCharacter() {
    if (weapon !=nullptr)
        delete weapon;
}

GameCharacter::GameCharacter(const GameCharacter& orig) {
    HP = orig.HP;
    armor = orig.armor;
    posX = orig.posX;
    posY = orig.posY;

    if (orig.weapon)
        // In questo caso sto utilizzando il costruttore di copia di default creato dal compilatore
        // per la classe Weapon. Questo mi va bene perché Weapon ha solo attributi interi.
        weapon = new Weapon(*orig.weapon);
    else
        weapon = nullptr;

}

// Il valore di ritorno di questa funzione è un indirizzo
GameCharacter& GameCharacter::operator=(const GameCharacter& right) {
    // Faccio una verifica sugli indirizzi degli oggetti
    if (this != &right) {
        HP = right.HP;
        armor = right.armor;
        posX = right.posX;
        posY = right.posY;

        if (weapon)
            delete weapon;

        if (right.weapon !=nullptr)
            weapon = new Weapon(*right.weapon);
        else
            weapon = nullptr;
    }
    return *this;
}


int GameCharacter::getHP() const {
    return HP;
}

void GameCharacter::setHP(int hp) {
    this->HP = hp;
}

Weapon* GameCharacter::getWeapon() const {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    posX += x;
    posY += y;
}

void GameCharacter::move(int distance) {
    posX += distance;
    posY += distance;
}

int GameCharacter::getArmor() const {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter &enemy) const {
    bool success = false;

    int hit = 1;
    if (weapon)
        hit = weapon->use();

    int damage = 0;
    if (hit > enemy.getArmor()) {
        damage = enemy.receiveDamage(hit);
    }

    if (damage) {
        cout << "You hit the enemy ! (HP: " << enemy.getHP() << " punti)" << endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

int GameCharacter::receiveDamage(int points) {
    if (armor > 4)
        points /= 3;
    else if (armor > 2)
        points /= 2;
    else if (armor >= 1)
        points -= 2;

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}


bool GameCharacter::isLegalFight(const GameCharacter &enemy) const {
    int maxDistance = 1;
    if (L1distance(*this, enemy) > maxDistance)
        return false;
    return true;
}

int GameCharacter::L1distance(const GameCharacter& gc1, const GameCharacter& gc2) {
    return (std::abs(gc1.getPosX() - gc2.getPosX()) + std::abs(gc1.getPosY() - gc2.getPosY()));
}
