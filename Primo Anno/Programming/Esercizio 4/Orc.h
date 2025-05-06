#ifndef E3_INHERITANCE_EXERCISE_ORC_H
#define E3_INHERITANCE_EXERCISE_ORC_H

#include "GameCharacter.h"

class Orc : public GameCharacter {
public:
    explicit Orc(int s, int hp = 20) : GameCharacter(hp), strength(s) {
    }

    virtual void move(int x, int y) override;

    virtual int fight(GameCharacter &enemy) override;

    // override base class method
    virtual char getCharacterSymbol() const override {
        return 'O';
    }

protected:
    int strength;
};


#endif //E3_INHERITANCE_EXERCISE_ORC_H
