/*
 * Character.cpp
 *
 */

#include "GameCharacter.h"

#include <ctime>
#include <iostream>

using namespace std;

GameCharacter::GameCharacter(int hp, int a) : HP(hp), armor(a), weapon(nullptr), posX(0), posY(0) {
    // position and weapon must be set to 0 or null pointer
    if (HP <= 0) {
        HP = 10;
    }
    if (armor <= 0) {
        armor = 10;
    }
}

int GameCharacter::getHP() {
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
    posX += x;
    posY += y;
}

void GameCharacter::move(int distance) {
    posX += distance;
    posY += distance;
}

int GameCharacter::getArmor() {
    return armor;
}

void GameCharacter::setArmor(int defense) {
    this->armor = defense;
}

bool GameCharacter::fight(GameCharacter& enemy) {
    int hit = 1;

    if (weapon != nullptr)
        hit = weapon->use();

    int damage = 0;
    if (hit > enemy.armor()) {
        damage = enemy.receiveDamage(hit);
    }

    bool success = false;
    if (damage) {
        std::cout << "You hit the enemy ! HP: " << enemy.HP << std::endl;
        success = true;
    } else
        cout << "You miss the hit..." << endl;
    return success;
}

int GameCharacter::receiveDamage(int points) {
    // TODO
    // if armor > 4 then points are divided by 3
    // if armor > 2 then points are divided by 2
    // if armor >= 1 then points are reduced by 2

    if (points <= 0)
        points = 1;

    HP -= points;
    if (points > 10)
        armor--;

    return points;
}

bool GameCharacter::isLegalFight(GameCharacter& enemy) {
    int maxDistance = 1;
    // FIXME: compute distance and return true if a character is within maxDistance along X or Y
    return true;
}
