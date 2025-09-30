//
// Created by neri on 23/07/25.
//

#include "WindowsFactory.h"

#include "WindowsDirectory.h"
#include "WindowsFile.h"
#include "WindowsPermission.h"

std::unique_ptr<File> WindowsFactory::createFile(std::string name, int dim) {
    return std::make_unique<WindowsFile>(name, dim);
}

std::unique_ptr<Directory> WindowsFactory::createDirectory(std::string name) {
    return std::make_unique<WindowsDirectory>(name);
}

std::unique_ptr<Permission> WindowsFactory::createPermission() {
    return std::make_unique<WindowsPermission>();
}
