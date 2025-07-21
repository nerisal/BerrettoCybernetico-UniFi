#include <map>
#include <string>
#include <iostream>

struct Articolo {
public:
    Articolo(std::string n, int i) : nome(n), qty(i) {}
    std::string nome;
    int qty; // quantità
};

class ShoppingList {
public:
    void printAll() const {
        for(auto item : shoppingList)
            std::cout << item.first << " - " << item.second << std::endl;
        std::cout << "------" << std::endl;
    }
    void add(const Articolo& item) {
        auto itr = shoppingList.find(item.nome);
        if (itr == shoppingList.end())
            shoppingList[item.nome] = item.qty;
        else
            shoppingList[item.nome] += item.qty;
    }
    void remove(const Articolo& item) {
        auto itr = shoppingList.find(item.nome);
        if (itr != shoppingList.end())
            shoppingList.erase(itr);
    }
private:
    std::map<std::string, int> shoppingList; // or std::map<std::string, Articolo>
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