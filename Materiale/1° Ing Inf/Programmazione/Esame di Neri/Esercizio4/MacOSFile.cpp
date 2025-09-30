//
// Created by neri on 23/07/25.
//

#include "MacOSFile.h"

void MacOSFile::rename(std::string newName) {
    if (newName[0] != '/') {
        name = newName;
    }
}
