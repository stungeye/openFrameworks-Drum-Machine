#include "sampler.h"

void Sampler::startPlaying(int key) {
    samples.at(key).trigger();
}

void Sampler::add(int key, std::string path, bool loop) {
    // Had to use emplace rather than [] or insert to avoid extra copying of object.
    samples.emplace(key, Sample(path, loop));
}

float Sampler::playAll() {
    float value{ 0 };
    for(auto& kv :samples) {
        value += kv.second.play();
    }
    return value;
}
