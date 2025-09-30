//
// Created by neri on 23/07/25.
//

#include "WindowsPermission.h"

void WindowsPermission::addUser(std::string current, std::string newUser) {
    auto itr = superUsers.end();
    for (auto i = superUsers.begin(); i != superUsers.end(); ++i) {
        if ((*i) == current) {
            itr = i;
        }
    }

    if (itr != superUsers.end()) {
        superUsers.push_back(newUser);
    }
}

void WindowsPermission::removeUser(std::string current, std::string removeUser) {
    superUsers.remove(removeUser);
}

void WindowsPermission::setReadingOnly(bool newValue) {
    onlyReading = newValue;
}
