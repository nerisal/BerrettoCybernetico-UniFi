#ifndef POTION_H
#define POTION_H

#include "GameCharacter.h"

enum class PotionType {
    HEALING_HP, DAMAGING_HP, RESTORING_MANA
};

class Potion {
public:
    explicit Potion(PotionType pt = PotionType::DAMAGING_HP);

    int use(GameCharacter& gc);

    std::string getDescription() const;

    friend std::ostream& operator<< (std::ostream& stream, Potion potion);

protected:
    int strength;
    int mana;
    PotionType potionType;
};


#endif //POTION_H
