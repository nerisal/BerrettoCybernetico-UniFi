#ifndef INVENTORY_H
#define INVENTORY_H

template<typename T, int N = 5>
class Inventory {
public:
    Inventory();
    Inventory(const Inventory<T>& right);
    Inventory<T>& operator=(const Inventory<T>& right);
    virtual ~Inventory() {
        delete[] elements;
        delete[] usedElements;
    }
    bool setElement(int pos, const T& value);
    bool getElement(int pos, T& value) const;

    int getMaxElements() const;

    virtual void printContent() const;

protected:
    int maxElements;
    T* elements; // XXX alternatively: T elements[N]; // static allocation  - no need to delete!
    bool* usedElements; // XXX alternatively: bool usedElements[N]; // static allocation  - no need to delete!
};

template<typename T, int N>
Inventory<T, N>::Inventory() : maxElements(N) {
    elements = new T[maxElements];
    usedElements = new bool[maxElements];
    for (int i = 0; i < maxElements; i++)
        usedElements[i] = false;
}

template<typename T, int N>
bool Inventory<T, N>::setElement(int pos, const T &value) {
    if (pos >= 0 && pos < maxElements && !usedElements[pos]) {
        elements[pos] = value;
        usedElements[pos] = true;
        return true;
    }
    return false;
}

template<typename T, int N>
bool Inventory<T, N>::getElement(int pos, T &value) const {
    if (pos >= 0 && pos < maxElements && usedElements[pos]) {
        value = elements[pos];
        usedElements[pos] = false;
        return true;
    }
    return false;
}

template<typename T, int N>
int Inventory<T, N>::getMaxElements() const {
    return maxElements;
}

template<typename T, int N>
void Inventory<T, N>::printContent() const {
    for (int i = 0, num = 0; i < maxElements; i++, num++) {
        T element;
        if (getElement(i, element))
            std::cout << num << ":" << element << std::endl;
    }
}


#endif //INVENTORY_H
