//
// Created by Marco Bertini on 21/03/18.
//

#include "Dice.h"

#include <ctime> // for time
#include <cstdlib> // for rand and srand

int Dice::rollsCount = 0;

// read: https://stackoverflow.com/questions/7343833/srand-why-call-it-only-once
Dice::Dice() :Dice(6){}
Dice::Dice(const int f) : faces(f) {
    srand(time(0));
}

int Dice::roll(const int r) const {
    int result=0;

    if (rollsCount >= ROLLS_LIMIT) {
        srand(time(0));
        rollsCount = 0;
    }
    // read: https://stackoverflow.com/questions/1452934/what-is-the-meaning-of-xxx-in-code-comments

    for (int i=0; i<r; i++)
        result += rand() % faces;

    rollsCount++;

    return result;
}

