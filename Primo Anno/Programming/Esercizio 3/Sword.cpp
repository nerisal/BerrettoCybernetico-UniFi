//
// Created by Marco Bertini on 08/04/18.
//

#include "Sword.h"

int Sword::use() {
    int result = Weapon::use();
    if (valirian)
        result *= 2;
    return result;
}
