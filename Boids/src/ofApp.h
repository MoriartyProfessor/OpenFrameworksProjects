#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "flock.hpp"

#include "../../Utils/sliderRange.h"

class ofApp : public ofBaseApp {

  public:
    void setup() override;
    void update() override;
    void draw() override;
    void exit() override;

    void keyPressed(int key) override;
    void keyReleased(int key) override;
    void mouseMoved(int x, int y) override;
    void mouseDragged(int x, int y, int button) override;
    void mousePressed(int x, int y, int button) override;
    void mouseReleased(int x, int y, int button) override;
    void mouseScrolled(int x, int y, float scrollX, float scrollY) override;
    void mouseEntered(int x, int y) override;
    void mouseExited(int x, int y) override;
    void windowResized(int w, int h) override;
    void dragEvent(ofDragInfo dragInfo) override;
    void gotMessage(ofMessage msg) override;

  private:
    const std::string mName{"Boids"};
    ofColor mBackgroundColor{0, 5, 15};

    ofxSlider<std::size_t> mBoidCountSlider;
    ofxSlider<double> mSeparationSlider;
    ofxSlider<double> mAlignmentSlider;
    ofxSlider<double> mCohesionSlider;
    ofxSlider<double> mFlockRadiusSlider;

    const SliderRange<std::size_t> BOIDS_COUNT_RANGE{10, 10000, 2000};
    const SliderRange<double> BOID_PARAMETER_RANGES{0.0, 1.0, 0.2};
    const SliderRange<double> BOID_FLOCK_RADIUS_RANGES{0.0, 100.0, 2.0};

    bool mDisplayGUI = true;
    ofxPanel mGUI;

    Flock mFlock{BOIDS_COUNT_RANGE.DEFAULT};
};
