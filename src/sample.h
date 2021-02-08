#pragma once
#include "ofxMaxim.h"
#include <string>

class Sample {
public:
    Sample(std::string path, bool loop);
    Sample(const Sample& other) = delete;
    double play();
    void trigger();
private:
    ofxMaxiSample sample;
    std::string path;
    bool isLoop;
    bool isLooping;
};
