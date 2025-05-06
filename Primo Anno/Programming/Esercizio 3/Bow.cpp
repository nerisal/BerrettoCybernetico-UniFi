//
// Created by Marco Bertini on 08/04/18.
//

#include "Bow.h"

int Bow::use() {
    int result = 1;
    if (arrows > 0) {
        arrows--;
        result = Weapon::use();
    }
    return result;
}
