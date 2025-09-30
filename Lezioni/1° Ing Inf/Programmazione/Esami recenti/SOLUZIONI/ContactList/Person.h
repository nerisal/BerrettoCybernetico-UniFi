//
// Created by m3ta on 2/20/2018.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include "header.h"
#include "Email.h"
#include "Address.h"
#include "Number.h"

class Person  {
public:
    Person(){}
    Person(int id, string pn, string ps) : id(id), pName(pn), pSurname(ps){}

    void insertAddress(string typeAddr, string addr){
        Address* newAddress = new Address(typeAddr, addr);
        addresses.push_back(newAddress);
    }
    void insertEmail(string eType, string eName){
        Email* newMail = new Email(eType, eName);
        emails.push_back(newMail);
    }
    void insertNumber(string nType, string nValue){
        Number* newNumber = new Number(nType, nValue);
        numbers.push_back(newNumber);
    }
    void printContact(list<Person*>& contacts){
        for(auto itr : contacts) {
            itr->print();
        }
    }
    void print(){
        cout << "\nContact ID[" << id << "] ";
        cout << "Full name: " << pName << " " << pSurname << endl;
        if(!emails.empty()){
            email->printEmail(emails);
        }
        if(!numbers.empty()){
            number->printNumber(numbers);
        }
        if(!addresses.empty()){
            address->printAddress(addresses);
        }
    }


    void setPName(const string &pName) {
        Person::pName = pName;
    }

    void setPSurname(const string &pSurname) {
        Person::pSurname = pSurname;
    }

    int getId() const {
        return id;
    }

    void setId(int id) {
        Person::id = id;
    }

private:
    Email* email;
    Address* address;
    Number* number;
    string pName, pSurname;
    list<Email*> emails;
    list<Address*> addresses;
    list<Number*> numbers;
    int id;
};



#endif //UNTITLED_PERSON_H
