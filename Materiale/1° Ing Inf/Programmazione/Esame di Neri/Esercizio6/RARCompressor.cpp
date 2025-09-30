//
// Created by neri on 23/07/25.
//

#include "RARCompressor.h"

std::string RARCompressor::compressFile(std::string content) {
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == ' ') {
            content[i] = '-';
        }
    }

    return content;
}

std::string RARCompressor::decompressFile(std::string content) {
    for (int i = 0; i < content.size(); i++) {
        if (content[i] == '-') {
            content[i] = ' ';
        }
    }

    return content;
}
