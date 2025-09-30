//
// Created by neri on 23/07/25.
//

#ifndef FACTORY_H
#define FACTORY_H
#include <memory>
#include "Directory.h"
#include "File.h"
#include "Permission.h"

class Factory {
public:
    virtual ~Factory() = default;

    virtual std::unique_ptr<File>createFile(std::string name, int dim) = 0;
    virtual std::unique_ptr<Directory> createDirectory(std::string name) = 0;
    virtual std::unique_ptr<Permission> createPermission() = 0;
};

#endif //FACTORY_H
