//
// Created by m3ta on 2/20/2018.
//

#ifndef UNTITLED_ADDRESS_H
#define UNTITLED_ADDRESS_H

#include "header.h"

class Address {
public:
    Address(string at="", string an="") : aType(at), aName(an) {}

    void printAddress(list<Address*> addresses){
        for(auto itr : addresses)
            itr->printInfo();
    }
    void printInfo(){
        cout << "\t\t\t  " << aType << " address: " << aName << endl;
    }

    const string &getAType() const;
    void setAType(const string &aType);
    const string &getAName() const;
    void setAName(const string &aName);

private:
    string aType, aName;
};

const string &Address::getAType() const {
    return aType;
}

void Address::setAType(const string &aType) {
    Address::aType = aType;
}

const string &Address::getAName() const {
    return aName;
}

void Address::setAName(const string &aName) {
    Address::aName = aName;
}


#endif //UNTITLED_ADDRESS_H
