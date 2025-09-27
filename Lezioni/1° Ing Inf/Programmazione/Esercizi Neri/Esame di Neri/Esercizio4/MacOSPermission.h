//
// Created by neri on 23/07/25.
//

#ifndef MACOSPERMISSION_H
#define MACOSPERMISSION_H
#include <iostream>
#include <bits/ostream.tcc>

#include "Permission.h"


class MacOSPermission : public Permission{
public:
    MacOSPermission() : Permission() {
        superUsers.push_back("mainUser");
        std::cout << "MacOS permission created" << std::endl;
    }

    virtual void addUser(std::string current, std::string newUser) override;
    virtual void removeUser(std::string current, std::string removeUser) override;
    virtual void setReadingOnly(bool newValue) override;
};



#endif //MACOSPERMISSION_H
