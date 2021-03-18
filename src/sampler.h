#pragma once
#include <string>
#include <unordered_map>
#include "sample.h"

class Sampler {
public:
    void keyPressed(const int key);
    void keyReleased(const int key);
    void add(const int key, const std::string& path, const bool loop);
    double playAll();
private:
    unordered_map<int, Sample> samples;
    unordered_map<int, bool> keydown;
};

