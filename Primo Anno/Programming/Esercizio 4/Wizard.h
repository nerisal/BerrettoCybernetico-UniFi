#ifndef E3_INHERITANCE_EXERCISE_WIZARD_H
#define E3_INHERITANCE_EXERCISE_WIZARD_H

#include <string>
#include "GameCharacter.h"

class Wizard : public GameCharacter {
public:
    Wizard(std::string n, int m, int hp = 10, int armor = 5) : GameCharacter(hp, armor), name(n), mana(m) {}

    virtual int fight(GameCharacter &enemy) override;

    // in this class do not override move()

    // in derived classes we can introduce new behaviours, like this brand new method:
    virtual void doMagic(); // it's virtual: we expect to further derive and override its behaviour in derived classes

    // override base class method
    virtual char getCharacterSymbol() const override {
        return 'W';
    }

protected:
    int mana; // spiritual strength
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_WIZARD_H
