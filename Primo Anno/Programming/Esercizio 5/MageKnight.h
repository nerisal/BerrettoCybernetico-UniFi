#ifndef MAGEKNIGHT_H
#define MAGEKNIGHT_H

#include "Wizard.h"
#include "Knight.h"

class MageKnight : public Knight, public Wizard {
public:
    MageKnight(const std::string &n, int d, int hp, int armor, int m);

    virtual void move(int x, int y) override;
    virtual int fight(GameCharacter& enemy) override;

    virtual char getCharacterSymbol() const override {
        return 'M';
    }

};


#endif //MAGEKNIGHT_H
