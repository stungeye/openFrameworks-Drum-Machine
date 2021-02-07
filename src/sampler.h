#pragma once
#include <string>
#include <map>
#include "sample.h"

class Sampler {
public:
    void startPlaying(int key);
    void add(int key, std::string path, bool loop);
    float playAll();
private:
    map<int, Sample> samples;
};


/*
#include <map>
#include <string>
#include "ofxMaxim.h"

 struct Sample {
        bool playing;
        bool loop;
        ofxMaxiSample sample;

        Sample() {
            playing = false;
            loop = false;
        }

        Sample(ofxMaxiSample _sample, bool _loop) {
            playing = false;
            sample = _sample;
            loop = _loop;
        }
    };

class Sampler {
public:
    void add(int key, std::string path);
    ofxMaxiSample& sample(int key);
    bool keyMapped(int key);
    void startPlaying(int key);
    void stopPlaying(int key);
    float playAll();
    
private:
   
    std::map<int, Sample> samples;

};
*/
