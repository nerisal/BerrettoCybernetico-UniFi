//
// Created by neri on 23/07/25.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <list>
#include <memory>
#include <iostream>

#include "File.h"

class Directory {
protected:
        std::string name;
        std::list<std::shared_ptr<File>> files;

public:
        Directory(std::string name) : name(name) {}
        virtual ~Directory() {}

        virtual void addFile(std::shared_ptr<File> file) = 0;
        virtual void rename(std::string newName) = 0;

        // Dummy Functions
        void getFiles() {
                std::cout << name << ": " << std::endl;
                for (const auto& file : files) {
                        std::cout << file->getName() << " size: " << file->getDim() <<std::endl;
                }
        }
};

#endif //DIRECTORY_H
