//
// Created by neri on 23/07/25.
//

#include "LinuxFactory.h"

#include "LinuxDirectory.h"
#include "LinuxFile.h"
#include "LinuxPermission.h"

std::unique_ptr<Permission> LinuxFactory::createPermission() {
    return std::make_unique<LinuxPermission>();
}

std::unique_ptr<File> LinuxFactory::createFile(std::string name, int dim) {
    return std::make_unique<LinuxFile>(name, dim);
}

std::unique_ptr<Directory> LinuxFactory::createDirectory(std::string name) {
    return std::make_unique<LinuxDirectory>(name);
}
