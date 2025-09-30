//
// Created by neri on 23/07/25.
//

#ifndef FILE_H
#define FILE_H

#include <string>

class File {
protected:
    std::string name;
    int dim;
public:
    File(std::string name, int dim) : name(name), dim(dim) {}
    virtual ~File() {}

    virtual void rename(std::string newName) = 0;

    // Dummy method
    std::string getName() { return name; }
    int getDim() { return dim; }
};

#endif //FILE_H
