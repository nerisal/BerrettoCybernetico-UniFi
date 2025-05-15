#include <sstream>
#include "Sword.h"

Sword::Sword(int s, bool m, bool v) : Weapon(s, m), valirian(v) {
    // there could be some more code here...
    // or just keep it empty, as it makes more sense
}

int Sword::use() {
    int result = basicUse();
    if (valirian)
        result *= 2;
    return result;
}

Sword* Sword::clone() const {
    return new Sword(*this);
}

std::string Sword::getDescription() const {
    std::stringstream result;
    result << "Sword - strength: " << strength << " - magic: " << std::boolalpha << magic << " - valirian: " << valirian;
    return result.str();
}
