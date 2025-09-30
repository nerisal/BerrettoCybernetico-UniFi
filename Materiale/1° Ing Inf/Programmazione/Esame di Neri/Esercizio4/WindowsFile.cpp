//
// Created by neri on 23/07/25.
//

#include "WindowsFile.h"

void WindowsFile::rename(std::string newName) {
    if (newName[0] != '.' && newName != "") {
        name = newName;
    }
}