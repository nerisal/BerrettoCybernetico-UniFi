#ifndef VAULT_H
#define VAULT_H

#include <iostream>
#include "Inventory.h"

template<typename T, int N = 10>
class Vault : public Inventory<T, N> {
public:
    Vault(int x, int y) : posX(x), posY(y), closed(true) {}
    virtual ~Vault() {}

    virtual void printContent() const override;
    void open() {
        closed = false;
    }

    int getPosX() const {
        return posX;
    }
    int getPosY() const {
        return posY;
    }

protected:
    int posX, posY;
    bool closed;
};

template<typename T, int N>
void Vault<T, N>::printContent() const {
    if (!closed) {
        std::cout << "This vault contains: " << std::endl;
        // XXX use this to clarify it's a base's member (or compiler won't recognize these are inherited members)
        for (int i = 0, num = 0; i < this->maxElements; i++, num++) {
            T element;
            if (this->getElement(i, element))
                std::cout << num << ":" << element << std::endl;
        }
    }
}


#endif //VAULT_H
