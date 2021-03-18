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
};

