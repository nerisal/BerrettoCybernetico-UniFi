#include "Skeleton.h"
#include "Dice.h"

Skeleton::Skeleton(bool mr) : GameCharacter(10, 2), magicRecover(mr) {

}

// In some cases a skeleton will be healed by the attack !
int Skeleton::receiveDamage(int points) {
    Dice myDice(6);
    int hitChance = myDice.roll(2);
    if (hitChance > 10 && magicRecover) {
        HP += points;
        return (-points);
    } else {
        HP -= points;
        return points;
    }
}

