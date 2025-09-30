//
// Created by neri on 23/07/25.
//

#include "ZIPCompressor.h"

std::string ZIPCompressor::compressFile(std::string content) {
    // Toglie le doppie
    for (int i = 0; i < content.size(); i++) {
            if ( content[i] == 't') {
                content[i] = ' ';
            }
        }

    return content;
}

std::string ZIPCompressor::decompressFile(std::string content) {
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == ' ') {
            content[i] = 't';
        }
    }

    return content;
}
