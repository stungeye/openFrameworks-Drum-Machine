#pragma once
#include <vector>

class Visualizer {
public:
    void resize(const int x, const int y, const int width, const int height);
    void update(const double waveformValue);
    void draw();
private:
    int x;
    int y;
    int width;
    int height;
    int waveformIndex;
    std::vector<double> waveform;
};

