//
// Created by neri on 23/07/25.
//

#include "WindowsDirectory.h"

void WindowsDirectory::addFile(std::shared_ptr<File> file) {
    if (file != nullptr) {
        files.push_back(file);
    }
}

void WindowsDirectory::rename(std::string newName) {
    if (newName[0] != '.') {
        name = newName;
    }
}
