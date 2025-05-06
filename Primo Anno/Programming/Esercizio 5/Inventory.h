#ifndef INVENTORY_H
#define INVENTORY_H

// DONE implement template class Inventory
// it is a polymorphic class with a virtual printContent() method
// it represents a container of objects of the same type with a maximum number of stored objects
// defined at compile time (use a non-type template argument) or creation time (constructor parameter)
// use an array to store objects and an array of booleans to know if a slot is occupied or not
// default number of stored objects is 5
template <typename T,const int N = 5>
class Inventory {
public:
    Inventory() {
        for (int i = 0; i < N; i++) {
            usedElements[i] = false;
        }
    };
    virtual ~Inventory() {
        delete[] storedObjects;
        // DONE free resource used to store objects
        delete[] usedElements;
    }
    bool setElement(int pos, const T& object); // DONE arguments: position and object to be stored

    bool getElement(int pos, T& object) const; // DONE arguments: position and object to be retrieved

    T* getObject(const int pos) const {
        return storedObjects[pos];
    }

    int getMaxElements() const {
        return N;
    };

    virtual void printContent() const;

protected:
    int maxElements = N; // max number of objects that can be stored
    T storedObjects[N];
    // DONE array of stored objects
    bool usedElements[N];
};

// DONE void printContent() const: to print a stored element use:
// std::cout << num << ":" << element << std::endl;

template <typename T,const int N>
bool Inventory<T, N>::setElement(int pos,const T& object) {
    if (!usedElements[pos] && 0 <= pos && pos < N) {
        usedElements[pos] = true;
        storedObjects[pos] = object;
        return true;
    }
    return false;
}

template <typename T,const int N>
bool Inventory<T, N>::getElement(int pos, T& object) const {
    if (usedElements[pos]) {
        object = storedObjects[pos];
        usedElements[pos] = false;
        return true;
    }

return false;
}

template<typename T,const int N>
// :: Operatore di risoluzione di scopo
void Inventory<T, N>::printContent() const {
    std::cout << "Inventory content:" << std::endl;
    for (int i = 0; i < N; i++) {
        if (usedElements[i]) {
            // Operatore freccina-freccina
            std::cout << i << ":" << storedObjects[i] << std::endl;
        }
    }
}

#endif //INVENTORY_H
