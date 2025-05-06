//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_SKELETON_H
#define E3_INHERITANCE_EXERCISE_SKELETON_H
#include "GameCharacter.h"

class Skeleton : public GameCharacter{
public:
    // Idid: add magicRecover param in c'tor Nota: c'tor è un'abbreviazione per constructor
    explicit Skeleton(int hp = 8, int armor = 5, int magicRecover = false) : GameCharacter(hp, armor), magicRecover
    (magicRecover) {};

    int receiveDamage(int points) override;

    // override base class method
    char getCharacterSymbol() const override {
        return 'S';
    }

private:
    bool magicRecover;
};


#endif //E3_INHERITANCE_EXERCISE_SKELETON_H
