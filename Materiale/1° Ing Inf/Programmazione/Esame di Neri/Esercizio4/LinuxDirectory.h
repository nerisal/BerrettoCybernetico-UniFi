//
// Created by neri on 23/07/25.
//

#ifndef LINUXDIRECTORY_H
#define LINUXDIRECTORY_H
#include <iostream>
#include <string>

#include "Directory.h"


class LinuxDirectory  : public Directory {
public:
    LinuxDirectory(std::string name) : Directory(name) {
        std::cout << "Linux directory created" << std::endl;
    }

    virtual void rename(std::string newName) override;
    virtual void addFile(std::shared_ptr<File> file) override;
};



#endif //LINUXDIRECTORY_H
