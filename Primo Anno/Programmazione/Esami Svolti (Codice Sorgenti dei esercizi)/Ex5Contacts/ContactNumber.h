//
// Created by Monica Eron on 20/02/18.
//

#ifndef ES5_CONTACTS_CONTACTNUMBER_H
#define ES5_CONTACTS_CONTACTNUMBER_H

#include <iostream>
#include <cstring>

using namespace std;

class ContactNumber{
public:
    ContactNumber(string typeNum, string n) : typeNumber(typeNum), number(n){}
    virtual ~ContactNumber(){};
    void printNumber(){
        cout<< typeNumber << " number: " << number << endl;
    }

private:
    string typeNumber;
    string number;
};

#endif //ES5_CONTACTS_CONTACTNUMBER_H
