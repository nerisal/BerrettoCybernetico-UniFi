#include "Weapon.h"


int Weapon::use() {
    int result = strength;

    if (magic) {
        result *= 2;
    }

    return result;
}
