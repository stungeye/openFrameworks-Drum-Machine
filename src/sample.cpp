#include "sample.h"

Sample::Sample(std::string path, bool loop) :
sample(new ofxMaxiSample),
isPlaying(false),
isLoop(false)
{
    sample->load(path, 1);
}

float Sample::play() {
    return sample->playOnce();
}

void Sample::trigger() {
    sample->trigger();
}
