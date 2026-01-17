#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#include "starfield.h"

#include <memory>
#include <string>

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
    const std::string mName{"Starfield"};
    ofColor mBackgroundColor{ofColor::black};

    bool mDisplayGUI = true;
    ofxPanel mGUI;
    ofxSlider<std::size_t> mNumberOfStarsSlider;
    const struct {
        std::size_t min = 0;
        std::size_t max = 20000;
    } mNumberOfStarsRange;
    ofxSlider<double> mCameraSpeedSlider;
    const struct {
        double min = 0.0;
        double max = 0.03;
    } mCameraSpeedRanger;

    std::unique_ptr<Starfield> mStarfield;
};
