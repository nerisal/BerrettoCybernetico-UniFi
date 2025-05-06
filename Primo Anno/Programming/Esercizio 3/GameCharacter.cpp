/*
 * Character.cpp
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#include "GameCharacter.h"
#include "Dice.h"

#include <ctime>
#include <iostream>

using namespace std;

GameCharacter::GameCharacter(int hp, int a) : HP(hp), armor(a), posX(0), posY(0), weapon(nullptr), movements(1) {
}

GameCharacter::GameCharacter() : GameCharacter(10, 10) {}

GameCharacter::~GameCharacter() {
    if (weapon != nullptr)
        delete weapon;
}

GameCharacter::GameCharacter(const GameCharacter &original) {
    HP = original.HP;
    posX = original.posX;
    posY = original.posY;

    if (original.weapon != nullptr)
        weapon = new Weapon(*original.weapon);
    else
        weapon = nullptr;
}

GameCharacter &GameCharacter::operator=(const GameCharacter &right) {
    if (this != &right) {
        if (weapon != nullptr)
            delete weapon;

        HP = right.HP;
        posX = right.posX;
        posY = right.posY;

        if (right.weapon != nullptr)
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

Weapon* GameCharacter::getWeapon() {
    return weapon;
}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}

void GameCharacter::move(int x, int y) {
    if (x > movements)
        x = movements;
    if (y > movements)
        y = movements;
    posX += x;
    posY += y;
}

int GameCharacter::getArmor() const {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

int GameCharacter::fight(GameCharacter &enemy) {
    Dice myDice(6);

    int hit = 1;
    if (weapon)
        hit = weapon->use();

    int damage = 0;
    int hitChance = myDice.roll(2);
    if (hitChance > 4) { // OK we can hit
        hit += myDice.roll(1); // additional random damage
        if (hit > enemy.getArmor()) {
            damage = enemy.receiveDamage(hit);
        }
    }

    return damage;
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
    if ((abs(posX - enemy.posX) > maxDistance) || (abs(posY - enemy.posY) > maxDistance))
        return false;
    return true;
}

int GameCharacter::l1Distance(const GameCharacter &p, const GameCharacter &q) {
    int distance = abs(p.posX - q.posX) + abs(p.posY - q.posY);
    return distance;
}

int GameCharacter::getMovements() const {
    return movements;
}

void GameCharacter::setMovements(int movements) {
    GameCharacter::movements = movements;
}
