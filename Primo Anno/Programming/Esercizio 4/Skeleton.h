#ifndef E3_INHERITANCE_EXERCISE_SKELETON_H
#define E3_INHERITANCE_EXERCISE_SKELETON_H

#include "GameCharacter.h"

class Skeleton : public GameCharacter {
public:
    Skeleton(bool mr = false);

    virtual int receiveDamage(int points) override;

    // XXX no need to override other base class methods in this class

    // override base class method
    virtual char getCharacterSymbol() const override {
        return 'S';
    }

private:
    bool magicRecover;
};


#endif //E3_INHERITANCE_EXERCISE_SKELETON_H
