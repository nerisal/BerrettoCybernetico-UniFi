//
// Created by Marco Bertini on 08/04/18.
//

#include "Wizard.h"

void Wizard::doMagic() {
    if (mana > 1) {
        const int healingPotion = 5;
        HP += healingPotion;
        mana--;
    }
}

int Wizard::fight(GameCharacter &enemy) {
    int damage = 0;
    damage = GameCharacter::fight(enemy);
    if (mana > 20) {
        damage *= 2;
        mana--;
    } else if (mana > 10)
        damage += 2;
    return damage;
}
