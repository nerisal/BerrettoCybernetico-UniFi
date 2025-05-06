//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_ORC_H
#define E3_INHERITANCE_EXERCISE_ORC_H

#include "GameCharacter.h"

class Orc : public GameCharacter {
public:
    // GameCharacter(hp) lo uso per impostare con il costruttore di default della classe base, poi aggiungo il resto.
    explicit Orc(int s, int hp=20) : GameCharacter(hp), strength(s) {};

    int fight(GameCharacter& enemy) override;

    void move(int x, int y) override;

    // override base class method
    // Qui devo aggiungere anche la costanza perché la parola chiave override,
    // vuole che
    char getCharacterSymbol() const override{
        return 'O';
    }

protected:
    int strength;
};


#endif //E3_INHERITANCE_EXERCISE_ORC_H
