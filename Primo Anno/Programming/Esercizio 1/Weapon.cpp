#include "Weapon.h"


int Weapon::use() const {
    int result = strength;

    if (magic) {
        result *= 2;
    }

    return result;
}

void Weapon::setMagic(bool m) {
    magic = m;
}

bool Weapon::isMagic() const {
    return magic;
}

int Weapon::getStrength() const {
    return strength;
}


void Weapon::setStrength(int strength) {
    if (strength > 0) {
        this->strength = strength;
    }
}
