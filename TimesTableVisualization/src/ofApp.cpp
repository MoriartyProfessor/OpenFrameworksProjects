#include "ofApp.h"

constexpr std::size_t INITIAL_NUMBER_OF_POINTS = 200;
constexpr double INITIAL_FACTOR = 2.0;

void ofApp::setup() {
    ofSetWindowTitle(mName);
    ofSetBackgroundColor(mBackgroundColor);

    ofSetVerticalSync(true);
    ofEnableSmoothing();

    mGUI.setup();
    mGUI.add(mNumberOfPointsSlider.setup(
        "Number of Points", INITIAL_NUMBER_OF_POINTS, mNumberOfPointsRange.min,
        mNumberOfPointsRange.max, 4, 20));
    mGUI.add(mFactorSlider.setup("Factor", INITIAL_FACTOR, mFactorRanger.min,
                                 mFactorRanger.max));

    mTimesTable = std::make_unique<TimesTable>(INITIAL_NUMBER_OF_POINTS);
}

void ofApp::update() {
    mTimesTable->setNumberOfPoints(
        mNumberOfPointsSlider.getParameter().cast<std::size_t>());
    mTimesTable->setFactor(mFactorSlider.getParameter().cast<double>());
    mTimesTable->update();
}

void ofApp::draw() {
    mTimesTable->draw(ofGetWidth(), ofGetHeight());
    if (mDisplayGUI) {
        mGUI.draw();
    }
}

void ofApp::exit() {}

void ofApp::keyPressed(int key) {
    if (key == 'h') {
        mDisplayGUI = !mDisplayGUI;
    }
}

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
