#pragma once
#include "ofxMaxim.h"
#include <string>

class Sample {
public:
    Sample(std::string path, bool loop);
    void load(std::string path, bool loop);
    float play();
    void trigger();
private:
    shared_ptr<ofxMaxiSample> sample;
    bool isPlaying;
    bool isLoop;
};
