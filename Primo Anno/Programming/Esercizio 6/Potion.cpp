//
// Created by Marco Bertini on 24/04/18.
//

#include <sstream>
#include "Potion.h"

Potion::Potion(PotionType pt) : potionType(pt) {
    switch(potionType) {
        case PotionType::DAMAGING_HP:
            strength = -10;
            mana = -2;
            break;
        case PotionType::HEALING_HP:
            strength = 10;
            mana = -1;
            break;
        case PotionType::RESTORING_MANA:
            strength = 0;
            mana = 2;
            break;
    }
}

std::string Potion::getDescription() const {
    std::stringstream result;
    switch(potionType) {
        case PotionType::DAMAGING_HP:
            result << "Damage (HP)" << strength << " - costs " << mana << " mana points";
            break;
        case PotionType::HEALING_HP:
            result << "Heal (HP): " << strength << " - costs " << mana << " mana points";
            break;
        case PotionType::RESTORING_MANA:
            result << "Restore (mana): " << mana << " mana points";
            break;
    }
    return result.str();
}

int Potion::use(GameCharacter &gc) {
    switch(potionType) {
        case PotionType::DAMAGING_HP:
        case PotionType::HEALING_HP:
            gc.setHP(gc.getHP()+strength);
            return mana;
        case PotionType::RESTORING_MANA:
            return mana;
    }
}

std::ostream &operator<<(std::ostream &stream, Potion potion) {
    stream << potion.getDescription(); // a friend can access a protected/private member
    return stream;
}
