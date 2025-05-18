#ifndef E3_INHERITANCE_EXERCISE_SWORD_H
#define E3_INHERITANCE_EXERCISE_SWORD_H

#include "Weapon.h"

class Sword final : public Weapon {
public:
    explicit Sword(int s, bool m = false, bool v = false);

    // DONE override pure virtual base method use()
    int use() override;

    // DONE implement clone method for ABC copy
    // Qui posso usare Sword perché è una classe derivata di Weapon
    Sword* clone() const override;

    bool isValirian() const {
        return valirian;
    }

    void setValirian(bool const valirian) {
        Sword::valirian = valirian;
    }

protected:
    bool valirian;
};


#endif //E3_INHERITANCE_EXERCISE_SWORD_H
