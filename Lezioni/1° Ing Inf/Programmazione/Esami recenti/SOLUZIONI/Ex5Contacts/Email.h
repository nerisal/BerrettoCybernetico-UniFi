//
// Created by Monica Eron on 20/02/18.
//

#ifndef ES5_CONTACTS_EMAIL_H
#define ES5_CONTACTS_EMAIL_H

#include <iostream>
#include <cstring>

using namespace std;

class Email{
public:
    Email(string t, string e): typeEmail(t), emailAddress(e){}
    virtual ~Email(){}
    void printEmail(){
        cout << typeEmail << " email: " << emailAddress<< endl;
    }
private:
    string typeEmail;
    string emailAddress;
};
#endif //ES5_CONTACTS_EMAIL_H
