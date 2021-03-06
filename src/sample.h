#pragma once
#include "ofxMaxim.h"
#include <string>

class Sample {
public:
    Sample(const std::string& path, const bool loop);
    Sample(const Sample& other) = delete;
    double play();
    void trigger();
private:
    ofxMaxiSample sample;
    std::string path;
    bool isLoop;
    bool isLooping;
};
