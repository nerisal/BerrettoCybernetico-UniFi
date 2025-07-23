//
// Created by neri on 23/07/25.
//

#ifndef COMPRESSOR_H
#define COMPRESSOR_H
#include <string>


class Compressor {
public:
    virtual ~Compressor() {}

    virtual std::string compressFile(std::string content) = 0;
    virtual std::string decompressFile(std::string content) = 0;
};



#endif //COMPRESSOR_H
