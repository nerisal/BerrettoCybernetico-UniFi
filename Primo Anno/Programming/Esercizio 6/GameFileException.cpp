#include <iostream>
#include "GameFileException.h"

// FIXME extend std::runtime_error - set whatMsg as error message of base class
// FIXME set attributes
GameFileException::GameFileException(std::string whatMsg, std::string file_name, bool f) : std::runtime_error(whatMsg), fileName(file_name), fatalError(f){
    // ... more code if needed
}

void GameFileException::printError() const {
    /* FIXME add file name */
    std::cerr << "Missing file: " << fileName << std::endl;
}