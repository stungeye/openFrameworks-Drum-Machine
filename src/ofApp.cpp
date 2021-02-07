#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

    int sampleRate = 48000; // Had to match the 48khz of the VoiceMeeter Asio Virtual Aux 
    int bufferSize = 7168;  // What does this do to latency?
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundStreamSettings settings;

    // Needed to use ASIO to get low latency. DS and WASAPI were too laggy.
    auto devices = soundStream.getDeviceList(ofSoundDevice::Api::MS_ASIO);
    for (int i{0}; i < devices.size(); ++i) {
        std::cout << devices[i] << "\n";
    }

    settings.setApi(ofSoundDevice::Api::MS_ASIO);
    settings.setOutDevice(devices[0]);
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;

    soundStream.setup(settings);

    sampler.add('q', ofToDataPath("roland_tr_909_1.wav"), false);
    sampler.add('w', ofToDataPath("breakbeats_1_1.wav"), true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    /////////////// waveform
    ofTranslate(0, ofGetHeight() / 2);
    ofSetColor(0, 255, 0);
    ofFill();
    ofDrawLine(0, 0, 1, waveform[1] * ofGetHeight() / 2.); //first line
    for (int i = 1; i < (ofGetWidth() - 1); ++i) {
        ofDrawLine(i, waveform[i] * ofGetHeight() / 2., i + 1, waveform[i + 1] * ofGetHeight() / 2.);
    }
}

void ofApp::audioOut(ofSoundBuffer& output) {
    std::size_t outChannels = output.getNumChannels();

    for (auto i = 0; i < output.getNumFrames(); i++) {
        float value = sampler.playAll();
        output[2 * i] += value;
        output[2 * i + 1] += value;
        waveform[waveIndex] = output[2 * i];


        if (waveIndex < (ofGetWidth() - 1)) {
            ++waveIndex;
        }
        else {
            waveIndex = 0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    sampler.startPlaying(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
