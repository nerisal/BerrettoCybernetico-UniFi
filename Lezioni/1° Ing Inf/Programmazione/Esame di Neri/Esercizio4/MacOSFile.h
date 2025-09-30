//
// Created by neri on 23/07/25.
//

#ifndef MACOSFILE_H
#define MACOSFILE_H
#include <iostream>
#include <string>
#include <bits/ostream.tcc>

#include "File.h"


class MacOSFile : public File{
public:
    MacOSFile(std::string name, int dim) : File(name, dim) {
        std::cout << "MacOS file created" << std::endl;
    }

    virtual void rename(std::string newName) override;
};



#endif //MACOSFILE_H
