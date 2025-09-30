//
// Created by neri on 23/07/25.
//

#ifndef RARCOMPRESSOR_H
#define RARCOMPRESSOR_H

#include "Compressor.h"

class RARCompressor : public Compressor{
public:
    virtual std::string compressFile(std::string content) override;
    virtual std::string decompressFile(std::string content) override;
};



#endif //RARCOMPRESSOR_H
