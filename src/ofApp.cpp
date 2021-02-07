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

    shared_ptr<ofxMaxiSample> sound1(new ofxMaxiSample);
    sound1->load(ofToDataPath("roland_tr_909_1.wav"), 1);
    shared_ptr<ofxMaxiSample> sound2(new ofxMaxiSample);
    sound2->load(ofToDataPath("roland_tr_909_2.wav"), 1);
    shared_ptr<ofxMaxiSample> sound3(new ofxMaxiSample);
    sound3->load(ofToDataPath("roland_tr_909_3.wav"), 1);
    shared_ptr<ofxMaxiSample> sound4(new ofxMaxiSample);
    sound4->load(ofToDataPath("roland_tr_909_4.wav"), 1);
    shared_ptr<ofxMaxiSample> sound5(new ofxMaxiSample);
    sound5->load(ofToDataPath("roland_tr_909_5.wav"), 1);
    shared_ptr<ofxMaxiSample> sound6(new ofxMaxiSample);
    sound6->load(ofToDataPath("roland_tr_909_6.wav"), 1);
    shared_ptr<ofxMaxiSample> sound7(new ofxMaxiSample);
    sound7->load(ofToDataPath("breakbeats_1_1.wav"), 1);

    keys.push_back(Key(sound1, 'a'));
    keys.push_back(Key(sound2, 's'));
    keys.push_back(Key(sound3, 'd'));
    keys.push_back(Key(sound4, 'f'));
    keys.push_back(Key(sound5, 'g'));
    keys.push_back(Key(sound6, 'h'));
    keys.push_back(Key(sound7, 'p', true));
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
        for (auto it = keys.begin(); it != keys.end(); it++) {
            float value{0};
            if (it->playing && it->loop) {
                value = it->sample->playLoop(0, 1);
            }
            else if (!it->loop) {
                value = it->sample->playOnce();
            }
            output[2 * i] += value;
            output[2 * i + 1] += value;
            waveform[waveIndex] = output[2 * i];
        }

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
    for (auto it = keys.begin(); it != keys.end(); it++) {
        if (it->triggerLetter == key && !it->playing) {
            it->playing = true;
            it->sample->trigger();
        } else if (it->triggerLetter == key && it->loop) {
            it->playing = false;
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    for (auto it = keys.begin(); it != keys.end(); it++) {
        if (it->triggerLetter == key && !it->loop) {
            it->playing = false;
        }
    }
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
