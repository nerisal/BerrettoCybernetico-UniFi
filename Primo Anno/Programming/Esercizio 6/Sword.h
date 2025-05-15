#ifndef SWORD_H
#define SWORD_H

#include <ostream>
#include "Weapon.h"

class Sword : public Weapon {
public:
    explicit Sword(int s = 10, bool m = false, bool v = false);

    virtual int use() override;
    virtual Sword* clone() const override; // covariant return type

    bool isValirian() const {
        return valirian;
    }

    void setValirian(bool valirian) {
        Sword::valirian = valirian;
    }

protected:
    bool valirian;

    virtual std::string getDescription() const override;
};


#endif //SWORD_H
