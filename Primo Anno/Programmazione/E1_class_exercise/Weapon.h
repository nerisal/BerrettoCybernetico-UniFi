#ifndef WEAPON_H
#define WEAPON_H

class Weapon {
public:
    // Si creano due variabili s e m all'interno della classe.
    Weapon(int s, bool m = false) : strength(s), magic(m) {
        // Nel corpo del costruttore si possono fare dei controlli sul valore

        if (strength <= 0) {
            strength = 10; // TODO is this ok?
        }
    }

    int use();

    void setMagic(bool m) {
        magic = m;
    }

    bool isMagic() {
        return magic;
    }

    int getStrenght() const {
        return strength;
    }

    void setStrenght(int strength) {
        if (strength > 0) {
            this->strength = strength;
        }
    }

protected:
    int strength;
    bool magic;
};

#endif //WEAPON_H
