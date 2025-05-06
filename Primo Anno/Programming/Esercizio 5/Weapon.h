//
// Created on: 13/mar/2018
//  Author: bertini
//

#ifndef WEAPON_H
#define WEAPON_H

#include <ostream>

class Weapon {
public:
    Weapon();
    explicit Weapon(int s = 10, bool m = false);
    virtual ~Weapon() {} // XXX polymorphic destructor !

    virtual int use() = 0;
    virtual Weapon* clone() const = 0;

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

    friend std::ostream& operator<< (std::ostream& stream, Weapon* weapon);

protected:
    int strength;
    bool magic;

    virtual int basicUse();
    virtual std::string getDescription() const = 0;
};

#endif // WEAPON_H
