//
// Created by neri on 23/07/25.
//

#ifndef MACOSFACTORY_H
#define MACOSFACTORY_H
#include "Factory.h"


class MacOsFactory : public Factory{
public:
    virtual std::unique_ptr<File> createFile(std::string name, int dim) override;
    virtual std::unique_ptr<Directory> createDirectory(std::string name) override;
    virtual std::unique_ptr<Permission> createPermission() override;
};

#endif //MACOSFACTORY_H
