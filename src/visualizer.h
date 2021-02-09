#pragma once
#include <vector>

class Visualizer {
public:
    void resize(int x, int y, int width, int height);
    void update(double waveformValue);
    void draw();
private:
    int x;
    int y;
    int width;
    int height;
    int waveformIndex;
    std::vector<double> waveform;
};

