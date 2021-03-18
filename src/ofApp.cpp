#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {

    int sampleRate = 48000; // Had to match the 48khz of the VoiceMeeter Asio Virtual Aux 
    int bufferSize = 7168;  // What does this do to latency?
    ofxMaxiSettings::setup(sampleRate, 2, bufferSize);
    ofSoundStreamSettings settings;

    // Needed to use ASIO to get low latency. DS and WASAPI were too laggy.
    auto devices = soundStream.getDeviceList(ofSoundDevice::Api::MS_ASIO);
    for (auto i{0}; i < devices.size(); ++i) {
        std::cout << devices[i] << "\n";
    }
    
    // Device 0 on my machine: [MS ASIO: 0] Voicemeeter AUX Virtual ASIO [in:8 out:8] (default in) (default out)
    // Using Voicemeeter Banana (VoiceMeeter Input) as the Windows default sound output device.
    // https://vb-audio.com/Voicemeeter/banana.htm
    settings.setApi(ofSoundDevice::Api::MS_ASIO);
    settings.setOutDevice(devices[0]); 
    settings.setOutListener(this);
    settings.sampleRate = sampleRate;
    settings.numOutputChannels = 2;
    settings.numInputChannels = 0;
    settings.bufferSize = bufferSize;

    soundStream.setup(settings);

    // Add drum hits to the sampler:
    sampler.add('q', ofToDataPath("roland_tr_909_1.wav"), false);
    sampler.add('w', ofToDataPath("roland_tr_909_2.wav"), false);
    sampler.add('e', ofToDataPath("roland_tr_909_3.wav"), false);
    sampler.add('r', ofToDataPath("roland_tr_909_4.wav"), false);
    sampler.add('t', ofToDataPath("roland_tr_909_5.wav"), false);
    sampler.add('y', ofToDataPath("roland_tr_909_6.wav"), false);

    // Add drum loops to the sampler:
    auto loopKeys = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
    for (auto key : loopKeys) {
        std::stringstream path;
        path << "breakbeats_" << (int)ofRandom(1, 4) << "_" << (int)ofRandom(1, 6) << ".wav";
        sampler.add(key, ofToDataPath(path.str()), true);
    }
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    visualizer.draw();
}

void ofApp::audioOut(ofSoundBuffer& output) {
    const std::size_t outChannels = output.getNumChannels();

    for (std::size_t i = 0; i < output.getNumFrames(); i++) {
        const auto value = sampler.playAll();
        output[2 * i] += value;
        output[2 * i + 1] += value;
        visualizer.update(output[2 * i]);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    sampler.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
    sampler.keyReleased(key);
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
    visualizer.resize(0, 0, w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
