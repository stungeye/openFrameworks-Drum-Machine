#include "sampler.h"
/*

void Sampler::add(int key, std::string path) {
    ofxMaxiSample temp;
    temp.load(path, 1);
    samples[key] = Sample(temp, false);
}

ofxMaxiSample& Sampler::sample(int key) {
    return samples.at(key).sample;
}

bool Sampler::keyMapped(int key) {
    return samples.find(key) != samples.end();
}

void Sampler::startPlaying(int key) {
    samples.at(key).playing = true;
    samples.at(key).sample.trigger();
}

void Sampler::stopPlaying(int key) {
    samples.at(key).playing = false;
}

float Sampler::playAll() {
    float value(0);
    for(std::pair<int, Sample> element : samples) {
        value += element.second.sample.playOnce();
    }
    return value;
}
*/
