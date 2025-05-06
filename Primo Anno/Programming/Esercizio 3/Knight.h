//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_KNIGHT_H
#define E3_INHERITANCE_EXERCISE_KNIGHT_H

#include <string>
#include <utility>
#include "GameCharacter.h"

// extend GameCharacter
class Knight : public GameCharacter{
public:
    explicit Knight(int HP = 10, int armor = 12, int dex = 1, bool pal = false,std::string name = "Artù") : GameCharacter(HP,
    armor),
    dexterity(dex), paladin(pal), name(std::move(name)) {};

    void setName(const std::string& n);
    std::string getName();

    void setDexterity(int d);
    int getDexterity() const;

    void setPaladin(bool p);
    bool isPaladin() const;


    int fight(GameCharacter& enemy) override;

    void move(int x, int y) override;

    // override base class method
    char getCharacterSymbol() const override {
        return 'K';
    }

private:
    int dexterity;
    bool paladin;
    std::string name;
};


#endif //E3_INHERITANCE_EXERCISE_KNIGHT_H
