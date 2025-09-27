#include "header.h"
#include "VideoPlayer.h"

int main() {
    VideoPlayer* vp = new VideoPlayer;
    vp->play("avi", "test.avi");
    vp->play("h246", "test.h246");
    vp->play("wmv", "test.wmv");
    vp->play("mp4", "test.mp4");

    return 0;
}