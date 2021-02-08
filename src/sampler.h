#pragma once
#include <string>
#include <unordered_map>
#include "sample.h"

class Sampler {
public:
    void keyPressed(int key);
    void keyReleased(int key);
    void add(int key, std::string path, bool loop);
    double playAll();
private:
    unordered_map<int, Sample> samples;
    unordered_map<int, bool> keydown;
    unordered_map<int, ofxMaxiSample> hits;
    unordered_map<int, ofxMaxiSample> loops;
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
