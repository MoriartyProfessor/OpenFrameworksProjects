#include "starfield.h"

#include "ofMain.h"

#include <chrono>
#include <random>

Starfield::Starfield(std::size_t size) { resize(size); }

void Starfield::resize(std::size_t newSize) { mStars.resize(newSize); }

void Starfield::update() {
    for (auto &star : mStars) {
        star.update(mCameraSpeed);
    }
}

void Starfield::draw(int width, int height) const {
    for (const auto &star : mStars) {
        star.draw(width, height);
    }
}

void Starfield::setCameraSpeed(double cameraSpeed) {
    mCameraSpeed = cameraSpeed;
}

Starfield::Star::Star() {
    static unsigned seed =
        std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 engine(seed);

    static std::uniform_real_distribution<double> coordDist(-1.0, 1.0);

    x = coordDist(engine);
    y = coordDist(engine);

    static std::uniform_real_distribution<double> zDist(2.0, 6.0);
    z = zDist(engine);

    static std::uniform_real_distribution<double> radiusDist(2.0, 5.0);
    r = radiusDist(engine);
}

void Starfield::Star::update(double cameraSpeed) {
    z -= cameraSpeed;
    if (z < 0.1) {
        *this = {};
    }
}

void Starfield::Star::draw(int width, int height) const {
    double screenX = ofMap(2.0 * x / z, -1.0, 1.0, 0, width);
    double screenY = ofMap(2.0 * y / z, -1.0, 1.0, 0, height);
    double screenR = r / z;
    ofDrawCircle(screenX, screenY, screenR);
}