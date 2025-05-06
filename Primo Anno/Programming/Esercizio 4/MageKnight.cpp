#include "MageKnight.h"

// TODO construct Knight (paladine=false) and Wizard
MageKnight::MageKnight(const std::string &n, int d, int hp, int armor, int m)  {}

int MageKnight::fight(GameCharacter &enemy) {
    int result = 0;
    // specific code...
    result += Knight::fight(enemy);
    // more code...
    return result;
}

void MageKnight::move(int x, int y) {
    Wizard::move(x, y);
}
