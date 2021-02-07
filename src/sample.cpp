#include "sample.h"

Sample::Sample(std::string path, bool loop) :
sample(new ofxMaxiSample),
isPlaying(false),
isLoop(false)
{
    sample->load(path, 1);
}

float Sample::play() const {
    return sample->playOnce();
}

void Sample::trigger() const {
    sample->trigger();
}
