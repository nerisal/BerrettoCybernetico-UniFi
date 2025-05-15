#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "GameFileException.h"
#include "FakeJPEG.h"

static const char* const SPLASH_SCREEN_FILENAME = "./res/splash_screen.fake_jpg";

const FakeJPEG* loadBitmap(std::string fileName);

void displaySplash();

#endif //SPLASH_SCREEN_H
