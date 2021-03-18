#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
<<<<<<< HEAD
=======
#include "sampler.h"
#include "visualizer.h"
>>>>>>> objectified

class ofApp : public ofBaseApp {

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    void audioOut(ofSoundBuffer& output) override;

private:
    ofSoundStream soundStream;
<<<<<<< HEAD
    float waveform[8192]; //make this bigger, just in case
    int waveIndex;
    vector<Key> keys;
=======
    Visualizer visualizer;
    Sampler sampler;
>>>>>>> objectified
};
