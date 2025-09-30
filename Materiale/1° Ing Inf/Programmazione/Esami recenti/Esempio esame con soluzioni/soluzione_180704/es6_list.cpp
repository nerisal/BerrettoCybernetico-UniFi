#include <list>
#include <string>
#include <algorithm>
#include <iostream>

struct Articolo {
public:
    Articolo(std::string n, int i) : nome(n), qty(i) {}
    bool operator==(const Articolo& right) const {
        return (nome == right.nome);
    }
    std::string nome;
    int qty; // quantità
};

class ShoppingList {
public:
    void printAll() const {
        for(auto item : shoppingList)
            std::cout << item.nome << " - " << item.qty << std::endl;
        std::cout << "------" << std::endl;
    }
    void add(const Articolo& item) {
        auto itr = std::find(shoppingList.begin(), shoppingList.end(), item);
        if (itr == shoppingList.end())
            shoppingList.push_back(item);
        else
            itr->qty += item.qty;
    }
    void remove(const Articolo& item) {
        auto itr = std::find(shoppingList.begin(), shoppingList.end(), item);
        if (itr != shoppingList.end())
            shoppingList.erase(itr);
    }
private:
    std::list<Articolo> shoppingList;
};

int main() {
    ShoppingList sl;
    Articolo item1("pasta", 1);
    Articolo item2("caffe", 2);
    Articolo item3("mele", 4);
    sl.add(item1);
    sl.add(item2);
    sl.add(item3);
    sl.printAll();
    sl.add(item1);
    sl.add(item3);
    sl.printAll();
    sl.remove(item3);
    sl.printAll();
}