//
// Created by neri on 23/07/25.
//

#ifndef GZIPCOMPRESSOR_H
#define GZIPCOMPRESSOR_H

#include "Compressor.h"

class GZIPCompressor : public Compressor{
    virtual std::string compressFile(std::string content) override;
    virtual std::string decompressFile(std::string content) override;
};



#endif //GZIPCOMPRESSOR_H
