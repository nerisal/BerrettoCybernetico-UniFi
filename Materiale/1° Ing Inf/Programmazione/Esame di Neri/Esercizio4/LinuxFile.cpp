//
// Created by neri on 23/07/25.
//

#include "LinuxFile.h"

void LinuxFile::rename(std::string newName) {
    if (newName != "") {
        name = newName;
    }
}