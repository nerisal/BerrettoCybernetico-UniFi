//
// Created by Marco Bertini on 08/04/18.
//

#ifndef E3_INHERITANCE_EXERCISE_SWORD_H
#define E3_INHERITANCE_EXERCISE_SWORD_H

#include "Weapon.h"

// Sword è di tipo pubblico, dunque Sword può sostituire Weapon
class Sword : public Weapon {
public:
    explicit Sword(int s, bool m = false, bool v = false) : Weapon(s, m), valirian(v){};
    //virtual int use() override;
    // Quando si riscrive un metodo basta rimettere solo un override.
    int use() override;

    bool isValirian() const {
        return valirian;
    }

    void setValirian(bool valirian) {
        Sword::valirian = valirian;
    }

protected:
    // GoT reference
    bool valirian;
};


#endif //E3_INHERITANCE_EXERCISE_SWORD_H
