#include "boid.hpp"

#include "../../Utils/scopedMatrix.h"

#include <iostream>

namespace Limits {
constexpr double POSITION_MIN = 0.0;
constexpr double POSITION_MAX = 100.0;
constexpr double VELOCITY_MIN = -12.0;
constexpr double VELOCITY_MAX = 12.0;
constexpr double ACCELARATION_MIN = -3.0;
constexpr double ACCELARATION_MAX = 3.0;
constexpr double SIZE = 0.3;

constexpr double VELOCITY_MIN_LENGTH = 1.5;
constexpr double VELOCITY_MAX_LENGTH = sqrt(2 * VELOCITY_MAX * VELOCITY_MAX);
constexpr double RECALL_FACTOR = 0.12;
} // namespace Limits

Boid::Parameters Boid::sParameters = {};

Boid::Boid() {
    static unsigned seed =
        std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 engine(seed);

    static std::uniform_real_distribution<double> posDist(Limits::POSITION_MIN,
                                                          Limits::POSITION_MAX);
    static std::uniform_real_distribution<double> velDist(Limits::VELOCITY_MIN,
                                                          Limits::VELOCITY_MAX);
    static std::uniform_real_distribution<double> accDist(
        Limits::ACCELARATION_MIN, Limits::ACCELARATION_MAX);

    mPosition.x = posDist(engine);
    mPosition.y = posDist(engine);

    mVelocity.x = velDist(engine);
    mVelocity.y = velDist(engine);

    mAccelaration.x = accDist(engine);
    mAccelaration.y = accDist(engine);
}

Boid::Boid(ofVec2f pos, ofVec2f vel, ofVec2f acc)
    : mPosition{pos}, mVelocity{vel}, mAccelaration{acc} {}

void Boid::update(const std::vector<Boid> &boids, size_t ind) {

    ofVec2f sepVec{}, avgPos{}, avgVel{};
    std::size_t inRadiusNeighbors{};
    for (size_t i = 0; i < boids.size(); ++i) {
        auto &neighbor = boids[i];
        if (ind == i ||
            (mPosition - neighbor.mPosition).length() > sParameters.flockRadius)
            continue;

        sepVec += mPosition - neighbor.mPosition;
        avgPos += neighbor.mPosition;
        avgVel += neighbor.mVelocity;

        ++inRadiusNeighbors;
    }

    if (inRadiusNeighbors > 0) {
        auto magnitude = mVelocity.length();
        sepVec /= inRadiusNeighbors;
        avgVel /= inRadiusNeighbors;
        avgPos /= inRadiusNeighbors;
        mVelocity += (avgVel - mVelocity) * sParameters.alignmentStrength;
        mVelocity += sepVec * sParameters.separationStrength;
        mVelocity += (avgPos - mPosition) * sParameters.cohesionStrength;
        mVelocity.scale(magnitude);
        
        if(mVelocity.length() < Limits::VELOCITY_MIN_LENGTH) {
            mVelocity *= 1.05;
        }
    }

    auto adjustedVelocity = mVelocity * ofGetLastFrameTime();

    mPosition += adjustedVelocity;
    if (mPosition.x > Limits::POSITION_MAX) {
        mVelocity.x -= Limits::RECALL_FACTOR;
    }
    if (mPosition.y > Limits::POSITION_MAX) {
        mVelocity.y -= Limits::RECALL_FACTOR;
    }
    if (mPosition.x < Limits::POSITION_MIN) {
        mVelocity.x += Limits::RECALL_FACTOR;
    }
    if (mPosition.y < Limits::POSITION_MIN) {
        mVelocity.y += Limits::RECALL_FACTOR;
    }
}

void Boid::draw(const size_t width, const size_t height) const {
    double screenX = ofMap(mPosition.y, Limits::POSITION_MIN,
                           Limits::POSITION_MAX, 0, width);
    double screenY = ofMap(mPosition.x, Limits::POSITION_MIN,
                           Limits::POSITION_MAX, 0, height);
    double size = ofMap(Limits::SIZE, Limits::POSITION_MIN,
                        Limits::POSITION_MAX, 0, width);

    ScopedMatrix push;

    ofTranslate(screenX, screenY);
    ofRotateRad(std::atan2(mVelocity.x, mVelocity.y) + PI / 2);

    float hue = ofMap(mVelocity.length(), 0.0, Limits::VELOCITY_MAX_LENGTH, 170,
                      0, true);
    ofColor color = ofColor::fromHsb(hue, 200, 200);

    ofSetColor(color);

    ofDrawTriangle(0, -size, size * 0.5, size * 0.866, -size * 0.5,
                   size * 0.866);
}