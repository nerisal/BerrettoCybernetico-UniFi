#include "Weapon.h"

Weapon::Weapon(int const s, bool const m) : strength(s), magic(m) {
}

Weapon::Weapon() : Weapon(10, false) {
}

int Weapon::basicUse() {
    int result = strength;
    if (magic)
        result *= 2;
    return result;
}