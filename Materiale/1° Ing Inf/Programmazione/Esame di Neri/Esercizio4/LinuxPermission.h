//
// Created by neri on 23/07/25.
//

#ifndef LINUXPERMISSION_H
#define LINUXPERMISSION_H
#include <iostream>
#include <bits/ostream.tcc>

#include "Permission.h"


class LinuxPermission : public Permission {
public:
    LinuxPermission() : Permission() {
        superUsers.push_back("root");
        std::cout << "Linux permission created" << std::endl;
    }

    virtual void addUser(std::string current, std::string newUser) override;
    virtual void removeUser(std::string current, std::string newUser) override;
    virtual void setReadingOnly(bool newValue) override;
};



#endif //LINUXPERMISSION_H
