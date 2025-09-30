//
// Created by neri on 23/07/25.
//

#ifndef LINUXFACTORY_H
#define LINUXFACTORY_H
#include "Factory.h"


class LinuxFactory : public Factory{
public:
    virtual std::unique_ptr<Permission> createPermission() override;
    virtual std::unique_ptr<File> createFile(std::string name, int dim) override;
    virtual std::unique_ptr<Directory> createDirectory(std::string name) override;
};



#endif //LINUXFACTORY_H
