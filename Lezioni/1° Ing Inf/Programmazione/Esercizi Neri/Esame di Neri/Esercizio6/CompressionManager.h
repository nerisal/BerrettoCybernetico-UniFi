//
// Created by neri on 23/07/25.
//

#ifndef COMPRESSIONMANAGER_H
#define COMPRESSIONMANAGER_H
#include <algorithm>
#include <string>

#include "Compressor.h"
#include "GZIPCompressor.h"
#include "RARCompressor.h"
#include "ZIPCompressor.h"


class CompressionManager {
private:
    Compressor* compressor;
    RARCompressor* rarCompressor;
    GZIPCompressor* gzipCompressor;
    ZIPCompressor* zipCompressor;
public:
    CompressionManager() : compressor(nullptr), rarCompressor(new RARCompressor), gzipCompressor(new GZIPCompressor()), zipCompressor(new ZIPCompressor()) {}
    ~CompressionManager() {
        delete rarCompressor;
        delete gzipCompressor;
        delete zipCompressor;
        delete compressor;
    }

    void setOptimalCompressor(const std::string &ext);
    std::string compressFile(const std::string &filename, const std::string &content);
    std::string decompressFile(const std::string &filename, const std::string &content);

    // Metodo dato nel comando.
    std::string getFileExtension(const std::string& filename) {
        auto rev_iter = std::find(filename.rbegin(), filename.rend(), '.');
        if (rev_iter != filename.rend()) {
            return std::string(rev_iter.base() - 1, filename.end());
        }
        return "";
    }
};



#endif //COMPRESSIONMANAGER_H
