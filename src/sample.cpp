#include "sample.h"

Sample::Sample(std::string path, bool loop) :
path(path),
isLoop(loop),
isLooping(false)
{
    sample.load(path, 0);
    sample.setPosition(1.0); // Move position to the end so it doesn't start playing.
}

double Sample::play() {
   if (isLoop) {
        if (isLooping) {
            return sample.playLoop(0, 1);
        } else {
            return 0;
        }
   } else {
        return sample.playOnce();
   }
}

void Sample::trigger() {
   if (isLoop) {
       isLooping = !isLooping;
   } 

   sample.trigger();
}
