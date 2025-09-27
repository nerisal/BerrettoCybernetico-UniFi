//
// Created by Monica Eron on 20/02/18.
//

#ifndef ES5_CONTACTS_ADDRESS_H
#define ES5_CONTACTS_ADDRESS_H

#include <iostream>
#include <cstring>

using namespace std;

class Address{
public:
    Address(string typeAddr, string a) : typeAddress(typeAddr), address(a){}
    virtual ~Address(){}
    void printAddress(){
        cout<< typeAddress << " address: " << address << endl;
    }

private:
    string typeAddress;
    string address;
};

#endif //ES5_CONTACTS_ADDRESS_H
