#pragma once
#include "ofxMaxim.h"
#include <string>

class Sample {
public:
    Sample(std::string path, bool loop);
    float play() const;
    void trigger() const;
private:
    shared_ptr<ofxMaxiSample> sample;
    bool isPlaying;
    bool isLoop;
};
