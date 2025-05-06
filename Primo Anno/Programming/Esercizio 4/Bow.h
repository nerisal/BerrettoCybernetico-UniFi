#ifndef E3_INHERITANCE_EXERCISE_BOW_H
#define E3_INHERITANCE_EXERCISE_BOW_H


#include "Weapon.h"

class Bow : public Weapon {
public:
    explicit Bow(int strength, int ar = 10, bool magic = false);

    // DONE override pure virtual base method use()
    int use() override;

    // DONE implement clone method for ABC copy
    Bow* clone() const override;

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
