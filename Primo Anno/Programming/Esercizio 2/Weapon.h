//
// Created on: 13/mar/2018
//  Author: bertini
//

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon();
    // In questo caso, il costruttore può essere chiamato con explicit,
    // questo perché, nonostante abbia due argomenti, può essere chiamato
    // con uno solo in quanto è presente un valore di default. Si definisce
    // dunque explicit.
    explicit Weapon(int s, bool m = false);

    int use() const;

    void setStrength(int s) {
        strength = s;
    }

    int getStrength() const {
        return strength;
    }

    void setMagic(bool m) {
        magic = m;
    }

    bool isMagic() const {
        return magic;
    }

protected:
    int strength;
    bool magic;
};

#endif // WEAPON_H
