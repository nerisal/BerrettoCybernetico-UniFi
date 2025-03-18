#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    // Si creano due variabili s e m all'interno della classe.
    explicit Weapon(int s, bool m = false) : strength(s), magic(m) {
        // Nel corpo del costruttore si possono fare dei controlli sul valore

        if (strength <= 0) {
            strength = 10; // TODO is this ok?
        }
    }

    // Le funzioni vengono definite nel file Weapon.cpp
    int use() const;

    bool isMagic() const; // Getter
    void setMagic(bool m); // Setter

    int getStrength() const; // Getter
    void setStrength(int strength); // Setter

protected:
    int strength;
    bool magic;
};

#endif //WEAPON_H
