//
// Created by neri on 23/07/25.
//

#include "GZIPCompressor.h"

std::string GZIPCompressor::compressFile(std::string content) {
    for (int i = 0; i < content.size(); i++) {
        if (i % 2 != 0) {
            content.erase(content.begin() + i);
        }
    }

    return content;
}

std::string GZIPCompressor::decompressFile(std::string content) {
    for (int i = 0; i < content.size(); i++) {
        if (i % 2 != 0) {
            content[i] = 'a';
        }
    }

    return content;
}
