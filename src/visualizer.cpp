#include "visualizer.h"
#include "ofMain.h"

void Visualizer::resize(int x, int y, int width, int height) {
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->waveformIndex = 0;
    waveform.resize(width, 0);
}

void Visualizer::update(double waveformValue) {
    if (waveform.size() > waveformIndex) {
        waveform[waveformIndex] = waveformValue;

        ++waveformIndex;
        if (waveformIndex >= width) {
            waveformIndex = 0;
        }
    }
}

void Visualizer::draw() {
    ofTranslate(x, y + height / 2);
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawLine(0, 0, 1, waveform[1] * height / 2.); //first line
    for (int i = 1; i < (width - 1); ++i) {
        ofDrawLine(i, waveform[i] * height / 2., i + 1, waveform[i + 1] * height / 2.);
    }
}
