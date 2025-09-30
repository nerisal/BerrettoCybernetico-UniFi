//
// Created by m3ta on 2/20/2018.
//

#ifndef UNTITLED_NUMBER_H
#define UNTITLED_NUMBER_H

#include "header.h"

class Number {
public:
    Number(string nt="", string nv="") : nType(nt), nValue(nv) {}

    void printNumber(list<Number*> numbers){
        for(auto itr : numbers)
            itr->printInfo();
    }

    void printInfo(){
        cout << "\t\t\t  " << nType << " number: " << nValue << endl;
    }

    const string &getNType() const;
    void setNType(const string &nType);
    const string &getNValue() const;
    void setNValue(const string &nValue);

private:
    string nType, nValue;
};

const string &Number::getNType() const {
    return nType;
}

void Number::setNType(const string &nType) {
    Number::nType = nType;
}

const string &Number::getNValue() const {
    return nValue;
}

void Number::setNValue(const string &nValue) {
    Number::nValue = nValue;
}


#endif //UNTITLED_NUMBER_H
