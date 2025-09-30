//
// Created by neri on 23/07/25.
//

#ifndef LINUXFILE_H
#define LINUXFILE_H
#include <iostream>
#include <bits/ostream.tcc>

#include "File.h"


class LinuxFile : public File{
public:
    LinuxFile(std::string name, int dim) : File(name, dim) {
        std::cout << "Linux file created" << std::endl;
    }

    virtual void rename(std::string newName) override;
};



#endif //LINUXFILE_H
