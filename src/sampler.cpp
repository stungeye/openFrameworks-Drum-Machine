#include "sampler.h"
#include <numeric>

void Sampler::keyPressed(int key) {
    if (keydown.find(key) == keydown.end()) return;

    // Without the keydown vector the sound could trigger repeatedly if we hold a key down.
    if (!keydown[key]) {
        keydown[key] = true;
        samples.at(key).trigger();
    }
}

void Sampler::keyReleased(int key) {
    if (keydown.find(key) == keydown.end()) return;

    keydown[key] = false;
}

void Sampler::add(int key, std::string path, bool loop) {
    // Had to use emplace rather than [] or insert to avoid extra copying of object.
    // What a gross thing to have to do. Without the piecewise_contruct emplace still does a copy.
    // Apparently in C++17 we could do this instead: samples.try_emplace(key, path, loop);
    samples.emplace(std::piecewise_construct, std::forward_as_tuple(key), std::forward_as_tuple(path, loop));
    keydown[key] = false;
}

double Sampler::playAll() {
    double value{ 0 };

    for(auto& kv : samples) {
        value += kv.second.play();
    }
    
    return value;
}
