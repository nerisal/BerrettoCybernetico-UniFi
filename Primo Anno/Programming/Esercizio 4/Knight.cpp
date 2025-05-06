#include "Knight.h"


Knight::Knight(std::string n, int d, int hp, int armor, bool p) : GameCharacter(hp, armor), name(n), dexterity(d),
                                                                  paladin(p) {

}

int Knight::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = basicFight(enemy);
    if (dexterity > 10)
        damage += basicFight(enemy);
    if (paladin)
        damage += 10;
    return damage;
}

void Knight::move(int x, int y) {
    // if dexterity > 10 allow +1 movement
    int addMovement = 0;
    if (dexterity > 10)
        addMovement = 1;
    if (x > (movements + addMovement))
        x = (movements + addMovement);
    if (y > (movements + addMovement))
        y = (movements + addMovement);
    posX += x;
    posY += y;
}

