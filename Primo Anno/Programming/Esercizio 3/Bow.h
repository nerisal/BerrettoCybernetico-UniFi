//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_BOW_H
#define E3_INHERITANCE_EXERCISE_BOW_H

// Prima occorre referenziare la classe Weapon nell'header
#include "Weapon.h"

// Dopodiché si può creare la casse derivata
class Bow : public Weapon {
public:
    // Siccome Weapon ha un costruttore non di default, devo chiamarlo io.
    explicit Bow (int strength, int a = 20) : Weapon(strength), arrows(a) {}

    // override use(). Each use should decrement arrows
    int use() override;

    int getArrows() const {
        return arrows;
    }

    void setArrows(int arrows) {
        Bow::arrows = arrows;
    }

protected:
    int arrows;
};


#endif //E3_INHERITANCE_EXERCISE_BOW_H
