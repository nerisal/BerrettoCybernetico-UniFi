#ifndef BOW_H
#define BOW_H


#include <ostream>
#include "Weapon.h"

class Bow : public Weapon {
public:
    explicit Bow(int strength, int ar = 10, bool magic = false);

    virtual int use() override;
    virtual Bow* clone() const override;

    int getArrows() const {
        return arrows;
    }

    void setArrows(int arrows) {
        Bow::arrows = arrows;
    }

protected:
    int arrows;

    virtual std::string getDescription() const override;
};


#endif //BOW_H
