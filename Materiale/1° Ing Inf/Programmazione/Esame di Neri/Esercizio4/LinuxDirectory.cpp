//
// Created by neri on 23/07/25.
//

#include "LinuxDirectory.h"

void LinuxDirectory::addFile(std::shared_ptr<File> file) {
    if (file != nullptr) {
        files.push_back(file);
    }
}

void LinuxDirectory::rename(std::string newName) {
    name = newName;
}
