//
// Created on: 13/mar/2018
//  Author: bertini
//

#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon();
    explicit Weapon(int s, bool m = false);

    // Essendo virtuale può essere riscritto nelle classi derivate
    virtual int use();

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

    // Essendoci almeno un metodo virtuale occorre mettere anche il distruttore come virtuale
    virtual ~Weapon();

protected:
    int strength;
    bool magic;
};

#endif // WEAPON_H
