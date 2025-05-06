#include "Orc.h"

void Orc::move(int x, int y) {
    int addMovement = 0;
    if (strength > 10)
        addMovement = 1;
    if (x > (movements + addMovement))
        x = (movements + addMovement);
    if (y > (movements + addMovement))
        y = (movements + addMovement);
    posX += x;
    posY += y;
}

int Orc::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = basicFight(enemy);
    if (strength > 10)
        damage += basicFight(enemy);;
    return damage;
}
