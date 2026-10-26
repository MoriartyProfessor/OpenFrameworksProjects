#include "flock.hpp"

Flock::Flock(size_t boidCnt) {
    mBoidsFront.resize(boidCnt);
    mBoidsBack = mBoidsFront;
}

void Flock::resize(const size_t boidCnt) {
    mBoidsFront.resize(boidCnt);
    if (mBoidsBack.size() > mBoidsFront.size()) {
        mBoidsBack.resize(mBoidsFront.size());
    } else {
        mBoidsBack.reserve(mBoidsFront.size());
        for (size_t i = mBoidsBack.size(); i < mBoidsFront.size(); ++i) {
            mBoidsBack.push_back(mBoidsFront[i]);
        }
    }
}

void Flock::setSeparationStrength(double sepStr) {
    Boid::sParameters.separationStrength = sepStr;
}

void Flock::setAlignmentStrength(double aliStr) {
    Boid::sParameters.alignmentStrength = aliStr;
}

void Flock::setCohesionStrength(double cohStr) {
    Boid::sParameters.cohesionStrength = cohStr;
}

void Flock::setFlockRadius(double flkDst) {
    Boid::sParameters.flockRadius = flkDst;
}

void Flock::update() {
    for (size_t i = 0; i < mBoidsBack.size(); ++i) {
        mBoidsBack[i].update(mBoidsFront, i);
    }
    mBoidsFront = mBoidsBack;
}

void Flock::draw(const size_t width, const size_t height) {
    for (const auto &b : mBoidsFront) {
        b.draw(width, height);
    }
}