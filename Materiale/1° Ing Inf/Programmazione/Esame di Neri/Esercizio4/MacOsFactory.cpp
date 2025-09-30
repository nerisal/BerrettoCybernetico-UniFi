//
// Created by neri on 23/07/25.
//

#include "MacOsFactory.h"
#include "MacOSDirectory.h"
#include "MacOSFile.h"
#include "MacOSPermission.h"

inline std::unique_ptr<File> MacOsFactory::createFile(std::string name, int dim) {
    return std::make_unique<MacOSFile>(name, dim);
}

inline std::unique_ptr<Directory> MacOsFactory::createDirectory(std::string name) {
    return std::make_unique<MacOSDirectory>(name);
}

inline std::unique_ptr<Permission> MacOsFactory::createPermission() {
    return std::make_unique<MacOSPermission>();
}