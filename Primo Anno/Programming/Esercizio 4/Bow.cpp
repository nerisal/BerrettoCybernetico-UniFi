#include "Bow.h"

Bow::Bow(int strength, int ar, bool magic) : Weapon(strength, magic), arrows(ar) {

}

// DONE implement use(). Call basicUse() if there are enough arrows and update arrows number after use
int Bow::use() {
    if (arrows < 0) {
        return 0;
    }

    arrows--;

    return basicUse();
}

Bow* Bow::clone() const {
    return new Bow(*this);
}