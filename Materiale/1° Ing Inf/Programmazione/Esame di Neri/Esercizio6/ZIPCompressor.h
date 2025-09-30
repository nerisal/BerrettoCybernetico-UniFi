//
// Created by neri on 23/07/25.
//

#ifndef ZIPCOMPRESSOR_H
#define ZIPCOMPRESSOR_H

#include "Compressor.h"

class ZIPCompressor : public Compressor{
    virtual std::string compressFile(std::string content) override;
    virtual std::string decompressFile(std::string content) override;
};

#endif //ZIPCOMPRESSOR_H
