//
// Created by UserW7m3ra on 7/21/2017.
//

#ifndef BERTINIBUYITEMS_ITEMS_H
#define BERTINIBUYITEMS_ITEMS_H


#include "header.h"
#include "Customer.h"


class Items  {
public:
    Items(string n, double p) : name(n), price(p){}
    const string &getName() const{return name;}
    double getPrice() const{return price;}
    void setPrice(double &newPrice){this->price = newPrice;}

private:
    string name;
    double price;
};
#endif //BERTINIBUYITEMS_ITEMS_H
