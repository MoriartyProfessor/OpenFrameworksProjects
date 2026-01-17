#include "ofApp.h"

#include <iostream>

constexpr std::size_t INITIAL_NUMBER_OF_STARS = 2000;
constexpr double INITIAL_CAMERA_SPEED = 0.01;

void ofApp::setup() {
    ofSetWindowTitle(mName);
    ofSetBackgroundColor(mBackgroundColor);

    ofSetVerticalSync(true);
    ofEnableSmoothing();

    mGUI.setup();
    mGUI.add(mNumberOfStarsSlider.setup(
        "Number of Stars", INITIAL_NUMBER_OF_STARS, mNumberOfStarsRange.min,
        mNumberOfStarsRange.max, 4, 20));
    mGUI.add(mCameraSpeedSlider.setup("Camera Speed", INITIAL_CAMERA_SPEED,
                                      mCameraSpeedRanger.min,
                                      mCameraSpeedRanger.max));

    mStarfield = std::make_unique<Starfield>(INITIAL_NUMBER_OF_STARS);
}

void ofApp::update() {
    mStarfield->resize(mNumberOfStarsSlider.getParameter().cast<std::size_t>());
    mStarfield->setCameraSpeed(
        mCameraSpeedSlider.getParameter().cast<double>());
    mStarfield->update();
}

void ofApp::draw() {
    mStarfield->draw(ofGetWidth(), ofGetHeight());
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

void ofApp::windowResized(int w, int h) {}

void ofApp::gotMessage(ofMessage msg) {}

void ofApp::dragEvent(ofDragInfo dragInfo) {}
