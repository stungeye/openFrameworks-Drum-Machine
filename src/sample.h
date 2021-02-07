#pragma once
#include "ofxMaxim.h"
#include <string>

class Sample {
public:
    void load(std::string path, bool loop);
private:
    ofxMaxiSample sample;
    bool isPlaying;
    bool isLoop;

};
