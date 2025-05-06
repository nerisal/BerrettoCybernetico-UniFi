//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_WIZARD_H
#define E3_INHERITANCE_EXERCISE_WIZARD_H

#include <string>
#include <utility>

#include "GameCharacter.h"

class Wizard : public GameCharacter {
    public:
    explicit Wizard(int hp = 10, int a = 5, int mana = 50, std::string name = "Merlino") : GameCharacter(hp,a), mana(mana), name(std::move(name)){}

    int fight(GameCharacter& enemy) override;

    // in derived classes we can introduce new behaviours, like this brand-new method:
    virtual void doMagic(); // it's virtual: we expect to further derive and override its behaviour in derived classes

    // override base class method
    char getCharacterSymbol() const override {
        return 'W';
    }

protected:
    int mana; // spiritual strength
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_WIZARD_H
