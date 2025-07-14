#include "header.h"
#include "PlayList.h"

int main() {
    Image firstImage("unifi.jpg", 40);
    Image secondImage("morgagni.png", 60);
    Image thirdImage("toscana.png", 60);

    Video firsVideo("sea.mp4", 40, 240);
    Video secondVideo("mountain.mp4", 60, 120);
    Audio audio("three castles.mp3", 10);

    PlayList playList(audio);

    playList.addImage(firstImage);
    playList.addVideo(firsVideo);
    playList.addImage(secondImage);
    playList.addImage(thirdImage);
    playList.addVideo(secondVideo);

    playList.play();


    return 0;
}