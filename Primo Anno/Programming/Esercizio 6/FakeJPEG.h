#ifndef FAKEJPEG_H
#define FAKEJPEG_H


#include <string>
#include <vector>
#include "GameFileException.h"

class FakeJPEG {
public:
    explicit FakeJPEG(int width=80, int height=25);
    void load(std::string fileName) throw(GameFileException, std::runtime_error);

    const std::vector<std::string> &getBitmap() const;

private:
    int width, height;
    std::vector<std::string> bitmap;
};


#endif //FAKEJPEG_H
