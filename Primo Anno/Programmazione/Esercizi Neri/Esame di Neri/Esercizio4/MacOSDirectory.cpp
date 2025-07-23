//
// Created by neri on 23/07/25.
//

#include "MacOSDirectory.h"

inline void MacOSDirectory::rename(std::string newName) {
    if (newName[0] != ' ') {
        name = newName;
    }
}

inline void MacOSDirectory::addFile(std::shared_ptr<File> file) {
    if (file != nullptr) {
        files.push_back(file);
    }
}