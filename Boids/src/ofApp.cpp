#include "ofApp.h"

void ofApp::setup() {
    ofSetWindowTitle(mName);
    ofSetBackgroundColor(mBackgroundColor);

    ofSetVerticalSync(true);
    ofEnableSmoothing();

    mGUI.setup();

    mGUI.add(mBoidCountSlider.setup(
        "Number of Boids", BOIDS_COUNT_RANGE.DEFAULT, BOIDS_COUNT_RANGE.MIN,
        BOIDS_COUNT_RANGE.MAX, 5, 20));

    mGUI.add(mSeparationSlider.setup(
        "Separation", 0.22, BOID_PARAMETER_RANGES.MIN,
        BOID_PARAMETER_RANGES.MAX, 5, 20));

    mGUI.add(mAlignmentSlider.setup("Alignment", 0.125,
                                    BOID_PARAMETER_RANGES.MIN,
                                    BOID_PARAMETER_RANGES.MAX, 5, 20));

    mGUI.add(mCohesionSlider.setup("Cohesion", 0.105,
                                   BOID_PARAMETER_RANGES.MIN,
                                   BOID_PARAMETER_RANGES.MAX, 5, 20));

    mGUI.add(mFlockRadiusSlider.setup(
        "Flock Radius", BOID_FLOCK_RADIUS_RANGES.DEFAULT,
        BOID_FLOCK_RADIUS_RANGES.MIN, BOID_FLOCK_RADIUS_RANGES.MAX, 5, 20));
}

void ofApp::update() {
    mFlock.resize(mBoidCountSlider.getParameter().cast<std::size_t>());
    mFlock.setSeparationStrength(
        mSeparationSlider.getParameter().cast<double>());
    mFlock.setAlignmentStrength(mAlignmentSlider.getParameter().cast<double>());
    mFlock.setCohesionStrength(mCohesionSlider.getParameter().cast<double>());
    mFlock.setFlockRadius(mFlockRadiusSlider.getParameter().cast<double>());
    mFlock.update();
}

void ofApp::draw() {
    mFlock.draw(ofGetWidth(), ofGetHeight());
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
