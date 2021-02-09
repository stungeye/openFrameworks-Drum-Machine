#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"
#include "sampler.h"
#include "visualizer.h"

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

    struct Key {
        shared_ptr<ofxMaxiSample> sample;
        char triggerLetter;
        bool playing;
        bool loop;
        Key(shared_ptr<ofxMaxiSample> _sample, char _triggerLetter, bool _loop = false) {
            playing = false;
            sample= _sample;
            triggerLetter = _triggerLetter;
            loop = _loop;
        }
    };

    ofSoundStream soundStream;
    Visualizer visualizer;
    float waveform[8192]; //make this bigger, just in case
    int waveIndex;
    vector<Key> keys;
    Sampler sampler;
};
