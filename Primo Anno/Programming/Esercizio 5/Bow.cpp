#include <sstream>
#include "Bow.h"

Bow::Bow(int strength, int ar, bool magic) : Weapon(strength, magic), arrows(ar) {

}

int Bow::use() {
    int result = 0;
    if (arrows) {
        result = basicUse();
        arrows--;
    }
    return result;
}

Bow* Bow::clone() const {
    return new Bow(*this);
}

std::string Bow::getDescription() const {
    std::stringstream result;
    result << "Bow - strength: " << strength << " - magic: " << std::boolalpha << magic << " - arrows: " << arrows;
    return result.str();
}