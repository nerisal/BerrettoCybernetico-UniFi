//
// Created by neri on 23/07/25.
//

#ifndef WINDOWSDIRECTORY_H
#define WINDOWSDIRECTORY_H

#include <iostream>

#include "Directory.h"


class WindowsDirectory : public Directory {
public:
    WindowsDirectory(std::string name) : Directory(name) {
        std::cout << "Windows directory created" << std::endl;
    }
    virtual void rename(std::string newName) override;
    virtual void addFile(std::shared_ptr<File>) override;
};

#endif //WINDOWSDIRECTORY_H
