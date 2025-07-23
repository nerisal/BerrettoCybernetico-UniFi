//
// Created by neri on 23/07/25.
//

#ifndef WINDOWSPERMISSION_H
#define WINDOWSPERMISSION_H

#include <iostream>
#include <bits/ostream.tcc>

#include "Permission.h"

class WindowsPermission : public Permission{
public:
    WindowsPermission() : Permission() {
        superUsers.push_back("admin");
        std::cout << "Windows permission created" << std::endl;
    }
    virtual void addUser(std::string current, std::string newUser) override;
    virtual void removeUser(std::string current, std::string removeUser) override;
    virtual void setReadingOnly(bool newValue) override;
};



#endif //WINDOWSPERMISSION_H
