
#ifndef TEMPLATE_STACK_STACK_H
#define TEMPLATE_STACK_STACK_H

#include <iostream>
#include <stdexcept>
#include <list>

template<typename T>
class Stack {
public:
    Stack() : size(100), top(-1) {}; //costruttore di default che crea Stack di dimensione 100
    explicit Stack(int s) : size(s), top(-1) {}; //costruttore che permette di inserire la dimensione
    ~Stack(){
        elements.clear();
        std::cout<<"Il distruttore ha cancellato tutti gli elementi!!"<<std::endl;
    }

    bool is_empty() const { //serve per controllare stato dello stack
        if (top == -1)
            return true;
        return false;
    }

    bool is_full() const { //serve per controllare stato dello stack
        if (top == size - 1)
            return true;
        return false;
    }

    bool pushElement(const T &element) {
        if (!is_full()) {
            top++;
            elements.push_back(element);
            return true;
        } else {
            std::cout << "Spazio insufficiente. Inserimento fallito" << std::endl;
            return false;
        }

    }

    T popElement() {
        if (!is_empty()) {
            T el = elements.back();
            elements.pop_back();
            top--;
            return el;
        } else
            std::cout << "Lo stack è vuoto!" << std::endl;
    }

    void printElements() const{
        for (auto itr=elements.begin();itr!=elements.end();itr++)
            std::cout<< *itr <<std::endl;
    }

private:
    int size; //dimensione dello stack
    int top; //posizione dell'ultimo elemento inserito
    std::list<T> elements; //lista che contiene gli elementi dello stack
};


#endif //TEMPLATE_STACK_STACK_H
