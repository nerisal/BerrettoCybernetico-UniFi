/*
 * Character.h
 *
 *  Created on: 13/mar/2018
 *  Author: bertini
 */

#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "Weapon.h"

class GameCharacter {
public:
    GameCharacter();
    explicit GameCharacter(int hp, int a);

    // Il distruttore in questo caso deve essere definito ed è necessario perché
    // l'oggetto GameCharacter ha fra gli argomenti un puntatore a un oggetto
    ~GameCharacter();
    GameCharacter(const GameCharacter& orig);
    GameCharacter& operator=(const GameCharacter& right);


    void move(int x, int y);
    void move(int distance);

    static int L1distance(const GameCharacter& gc1, const GameCharacter& gc2);

    int getPosX() const {
        return posX;
    }
    void setPosX(const int posX) {
        GameCharacter::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        GameCharacter::posY = posY;
    }

    int getHP() const;
    void setHP(int hp);

    //Weapon è un oggetto, quindi va passato per riferimento con un puntatore.
    Weapon* getWeapon() const;
    void setWeapon(Weapon* weapon);

    int getArmor() const;
    void setArmor(int defense);

    bool fight(GameCharacter &enemy) const;
    bool isLegalFight(const GameCharacter &enemy) const;

    int receiveDamage(int points);

private:
    int HP;
    int armor;
    int posX;
    int posY;
    Weapon* weapon;
};

#endif // CHARACTER_H_
