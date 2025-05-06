#ifndef VAULT_H
#define VAULT_H

#include <iostream>
#include "Inventory.h"

// DONE implement Vault class extending inventory
// it represents a container of objects of the same type with a maximum number of stored objects
// defined at compile time (use a non-type template argument) or creation time (constructor parameter)
// default number of stored objects is 10
// it has a (x,y) position and a closed bool attribute with an open() method that sets it to false (set to true in constrctor).
// Overriden printContent method can print content only if closed == false

template <typename T,const int N = 10>
class Vault : public Inventory<T, N> {
public:
    explicit Vault(const int x = 0, const int y = 0) : Inventory<T, N>(), closed(true), posX(x), posY(y) {}
    // DONE set position and closed in constructor
    virtual ~Vault() {}

    void printContent() const override;

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
    // DONE add (x,y) position and closed Boolean attributes
    int posX, posY;
    bool closed;
};

// DONE overridden printContent method should print content only if not closed
// use: std::cout << num << ":" << element << std::endl;

template <typename T,const int N>
void Vault<T, N>::printContent() const{
    if (!closed) {
        std::cout << "This vault contains: " << std::endl;
        for (int i = 0; i < N; i++) {
            if (this->usedElements[i]) {
                std::cout << i << ":" << this->storedObjects[i] << std::endl;
            }
        }
    }
}

#endif //VAULT_H
