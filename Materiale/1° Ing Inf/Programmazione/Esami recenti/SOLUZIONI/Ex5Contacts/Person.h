//
// Created by Monica Eron on 20/02/18.
//

#ifndef ES5_CONTACTS_PERSON_H
#define ES5_CONTACTS_PERSON_H

#include <iostream>
#include <cstring>
#include <list>
#include "Address.h"
#include "Email.h"
#include "ContactNumber.h"

using namespace std;

class Person{
public:
    Person(string n, string s) : name(n), surname(s){}
    ~Person(){
        addresses.clear();
        emails.clear();
        numbers.clear();
    }

    void addAddress(string typeAddr, string address){
        Address* a= new Address(typeAddr, address);
        addresses.push_back(a);
    };
    void addEmail(string type, string email){
        Email* e = new Email(type,email);
        emails.push_back(e);
    };
    void addTelephone(string type, string number){
        ContactNumber* n = new ContactNumber(type, number);
        numbers.push_back(n);
    };

    void printInfo(){
        cout<< "Name: "<< name << endl;
        cout<< "Surname: " << surname << endl;
        if(!addresses.empty()){
            for(auto itr: addresses)
                itr->printAddress();
        }
        if(!emails.empty()){
            for(auto itr: emails)
                itr->printEmail();
        }
        if(!numbers.empty()){
            for(auto itr : numbers)
                itr->printNumber();
        }
    };

private:
    string name, surname;
    list<Address*> addresses;
    list<Email*> emails;
    list<ContactNumber*> numbers;

};
#endif //ES5_CONTACTS_PERSON_H
