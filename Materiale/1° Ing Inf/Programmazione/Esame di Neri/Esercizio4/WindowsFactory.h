//
// Created by neri on 23/07/25.
//

#ifndef WINDOWSFACTORY_H
#define WINDOWSFACTORY_H
#include "Factory.h"


class WindowsFactory : Factory {
public:
    virtual std::unique_ptr<File>createFile(std::string name, int dim) override;
    virtual std::unique_ptr<Directory> createDirectory(std::string name) override;
    virtual std::unique_ptr<Permission> createPermission() override;
};



#endif //WINDOWSFACTORY_H
