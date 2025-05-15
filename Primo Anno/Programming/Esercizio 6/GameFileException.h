#ifndef GAMEFILEEXCEPTION_H
#define GAMEFILEEXCEPTION_H

#include <string>
#include <exception>

class GameFileException : public std::runtime_error {
public:
    GameFileException(std::string whatMsg, std::string fileName, bool f=false);
    void printError() const;

    // DONE add getters for attributes
    // Per un'eccezione mi bastano i getters perché tanto una volta creato non
    // ci devo operare sopra.

    bool isFatal() const {
        return isFatal;
    }

private:
    // FIXME add useful attributes as fatal error and file name
    bool fatalError;
    std::string fileName;
};


#endif //GAMEFILEEXCEPTION_H
