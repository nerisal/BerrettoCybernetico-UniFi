//
// Created by m3ta on 2/20/2018.
//

#ifndef UNTITLED_EMAIL_H
#define UNTITLED_EMAIL_H
#include "header.h"

class Email {
public:
    Email(string et="", string en="") : eType(et), eName(en) {}

    void printEmail(list<Email*> emails){
        for(auto itr : emails)
            itr->printInfo();
    }
    void printInfo(){
        cout << "\t\t\t  " << eType << " email: " << eName << endl;
    }

    const string &getEType() const;
    void setEType(const string &eType);
    const string &getEName() const;
    void setEName(const string &eName);
private:
    string eType, eName;
};

const string &Email::getEType() const {
    return eType;
}

void Email::setEType(const string &eType) {
    Email::eType = eType;
}

const string &Email::getEName() const {
    return eName;
}

void Email::setEName(const string &eName) {
    Email::eName = eName;
}


#endif //UNTITLED_EMAIL_H
