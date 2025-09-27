//
// Created by neri on 23/07/25.
//

#ifndef MACOSDIRECTORY_H
#define MACOSDIRECTORY_H
#include <iostream>

#include "Directory.h"


class MacOSDirectory : public Directory {
public:
    MacOSDirectory(std::string name) : Directory(name) {
        std::cout << "MacOS directory created" << std::endl;
    }

    void rename(std::string newName) override;
    void addFile(std::shared_ptr<File> file) override;
};

#endif //MACOSDIRECTORY_H
