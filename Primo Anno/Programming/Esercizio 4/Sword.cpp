#include "Sword.h"

Sword::Sword(int s, bool m, bool v) : Weapon(s, m), valirian(v) {
    // there could be some more code here...
    // or just keep it empty, as it makes more sense
}

// DONE implement use().
// Call basicUse() and if valirian double the damage
int Sword::use() {
    int damage = Sword::basicUse();
    if (valirian) {
        damage *= 2;
    }
    return damage;
}

Sword* Sword::clone() const {
    return new Sword(*this);
}



