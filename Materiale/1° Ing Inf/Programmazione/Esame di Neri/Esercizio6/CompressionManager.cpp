//
// Created by neri on 23/07/25.
//

#include "CompressionManager.h"

void CompressionManager::setOptimalCompressor(const std::string &ext) {
    if (ext == ".txt") {
        compressor = zipCompressor;
    }else if (ext == ".docx") {
        compressor = gzipCompressor;
    }else if (ext == ".xls") {
        compressor = rarCompressor;
    }else
        compressor = nullptr;
}

std::string CompressionManager::compressFile(const std::string &filename, const std::string &content) {
    setOptimalCompressor(getFileExtension(filename));
    if (compressor != nullptr) {
        return compressor->compressFile(content);
    }

    return "";
}

std::string CompressionManager::decompressFile(const std::string &filename, const std::string &content) {
    setOptimalCompressor(getFileExtension(filename));
    if (compressor != nullptr) {
        return compressor->decompressFile(content);
    }

    return "";
}
