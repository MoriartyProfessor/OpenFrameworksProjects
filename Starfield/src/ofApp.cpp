#include "ofApp.h"

#include <iostream>

const std::size_t INITIAL_NUMBER_OF_STARS = 250;

void ofApp::setup() {
    ofSetWindowTitle(mName);
    ofSetBackgroundColor(mBackgroundColor);

    ofSetVerticalSync(true);

    mGUI.setup();
    mGUI.add(mNumberOfStarsSlider.setup(
        "Number of Stars", INITIAL_NUMBER_OF_STARS, mNumberOfStarsRange.min,
        mNumberOfStarsRange.max, 3, 16));

    mStarfield = std::make_unique<Starfield>(ofGetWidth(), ofGetHeight(),
                                             INITIAL_NUMBER_OF_STARS);
}

void ofApp::update() {
    mStarfield->resize(mNumberOfStarsSlider.getParameter().cast<std::size_t>());
    mStarfield->update();
}

void ofApp::draw() {
    mStarfield->draw();
    if (mDisplayGUI) {
        mGUI.draw();
    }
}

void ofApp::exit() {}

void ofApp::keyPressed(int key) {}

void ofApp::keyReleased(int key) {}

void ofApp::mouseMoved(int x, int y) {}

void ofApp::mouseDragged(int x, int y, int button) {}

void ofApp::mousePressed(int x, int y, int button) {}

void ofApp::mouseReleased(int x, int y, int button) {}

void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY) {}

void ofApp::mouseEntered(int x, int y) {}

void ofApp::mouseExited(int x, int y) {}

void ofApp::windowResized(int w, int h) { mStarfield->onWindowResize(w, h); }

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
