//
// Created by neri on 23/07/25.
//

#ifndef WINDOWSFILE_H
#define WINDOWSFILE_H

#include <iostream>
#include <bits/ostream.tcc>

#include "File.h"


class WindowsFile : public File{
public:
        WindowsFile(std::string name, int dim) : File(name, dim) {
                std::cout << "Windows file created" << std::endl;
        }

        virtual void rename(std::string newName) override;
};

#endif //WINDOWSFILE_H
