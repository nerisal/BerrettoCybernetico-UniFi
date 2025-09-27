//
// Created by m3ta on 2/20/2018.
//

#ifndef UNTITLED_CONTACT_H
#define UNTITLED_CONTACT_H

#include "header.h"
#include "Person.h"

class Contact {
public:
    Contact(int s = 10) : size(s){}
    Contact(list<Person*> p) : people(p){}
    void addPerson(Person* p){
            people.push_back(p);
    }
    void removePerson(Person* p){
        people.remove(p);
        cout << "Contact removed!" << endl;
    }
    void printContacts(){
        if(!people.empty()) {
            for (auto itr : people)
                itr->print();
        } else
            cout << "\nContact list is empty!" << endl;
    }
    ~Contact(){
        people.clear();
    }
private:
    int size;
    list<Person*> people;
};


#endif //UNTITLED_CONTACT_H
