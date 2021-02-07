#include "sample.h"

void Sample::load(std::string path, bool loop) {
    sample.load(path);
    isPlaying = false;
    isLoop = loop;
}
