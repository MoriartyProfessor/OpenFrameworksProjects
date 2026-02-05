#include "ofApp.h"

constexpr std::size_t INITIAL_NUMBER_OF_POINTS = 200;
constexpr double INITIAL_FACTOR = 2.0;

void ofApp::setup() {
    ofSetWindowTitle(mName);
    ofSetBackgroundColor(mBackgroundColor);

    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofEnableAntiAliasing();

    mGUI.setup();
    mGUI.add(mNumberOfPointsSlider.setup(
        "Number of Points", INITIAL_NUMBER_OF_POINTS, mNumberOfPointsRange.min,
        mNumberOfPointsRange.max, 4, 20));
    mGUI.add(mFactorSlider.setup("Factor", INITIAL_FACTOR, mFactorRanger.min,
                                 mFactorRanger.max));
    mGUI.add(mOscillate.setup("Oscillate", false));

    mTimesTable = std::make_unique<TimesTable>(INITIAL_NUMBER_OF_POINTS);
}

void ofApp::update() {
    static double oscillateDirection = 1.0;
    static constexpr double OSCILLATION_MAGNITUDE = 0.0005;
    if (mOscillate) {
        auto &factor = mFactorSlider.getParameter().cast<double>();
        if (factor >= mFactorRanger.max || factor <= mFactorRanger.min) {
            oscillateDirection *= -1.0;
        }
        factor += OSCILLATION_MAGNITUDE * oscillateDirection;
    }
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
    if ((key == OF_KEY_LEFT || key == OF_KEY_RIGHT) && mOscillate == false) {
        static constexpr double MAGNITUDE = 0.01;
        auto direction = key == OF_KEY_LEFT ? -1.0 : 1.0;
        auto &factor = mFactorSlider.getParameter().cast<double>();
        auto newFactor = factor + direction * MAGNITUDE;
        if (newFactor < mFactorRanger.max && newFactor > mFactorRanger.min) {
            factor = newFactor;
        }
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
