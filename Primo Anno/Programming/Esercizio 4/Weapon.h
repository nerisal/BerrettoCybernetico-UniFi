#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    Weapon();
    explicit Weapon(int s, bool m = false);
    virtual ~Weapon() {} // XXX polymorphic destructor !

    // DONE declare use() method (returning int) as pure virtual
    virtual int use() = 0;
    // Non posso più instanziare un metodo di tipo weapon.
    // Posso implementarla nelle classi derivate, ma non qui.

    // DONE declare a pure virtual clone method to implement ABC copy
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

protected:
    int strength;
    bool magic;

    // Questo metodo è visibile solo alle classi derivate.
    virtual int basicUse();
};

#endif // WEAPON_H
