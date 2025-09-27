//
// Created by Monica Eron on 20/02/18.
//

#ifndef ES5_CONTACTS_CONTACTS_H
#define ES5_CONTACTS_CONTACTS_H

#include <iostream>
#include <cstring>
#include <list>
#include "Person.h"

using namespace std;

class Contacts{
public:
    Contacts(int s = 10): size(s){}
    ~Contacts(){persons.clear();}

    void addPerson (Person* p){
        if(persons.size()<size) {
            persons.push_back(p);
            cout << "A new contact has been added." << endl;
        } else
            cout<< "No more space for new contacts"<< endl;
    };

    void removePerson (Person* p){
        persons.remove(p);
        cout<<"A contact has been removed."<< endl;
    };

    void printAllContacts(){
        cout << "------------------------" << endl;
        for(auto itr : persons) {
            itr->printInfo();
            cout << "------------------------" << endl;
        }
        cout<<"Total contacts: "<< persons.size() << endl;
    }

private:
    int size;
    list<Person*> persons;
};

#endif //ES5_CONTACTS_CONTACTS_H
