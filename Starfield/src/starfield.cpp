#include "starfield.h"

#include "ofMain.h"

#include <chrono>
#include <random>

Starfield::Starfield(int width, int height, std::size_t size)
    : mWidth{width}, mHeight{height}, mSize{size} {
    mStars.reserve(mSize);
    for (std::size_t i = 0; i < mSize; ++i) {
        mStars.emplace_back(mWidth, mHeight);
    }
}

void Starfield::resize(std::size_t size) {
    if (size == mSize)
        return;

    if (size > mSize) {
        mStars.reserve(size);
        for (std::size_t i = mSize; i < size; ++i) {
            mStars.emplace_back(mWidth, mHeight);
        }
    } else if (size < mSize) {
        mStars.resize(size, Star{mWidth, mHeight});
    }
    mSize = size;
}

void Starfield::onWindowResize(int width, int height) {
    for (auto &star : mStars) {
        star.onWindowResize(static_cast<double>(width) / mWidth,
                            static_cast<double>(height) / mHeight);
    }
    mWidth = width;
    mHeight = height;
}

void Starfield::update() {
    for (auto &star : mStars) {
        star.update();
    }
}

void Starfield::draw() const {
    for (const auto &star : mStars) {
        star.draw();
    }
}

Starfield::Star::Star(int width, int height) {
    static unsigned seed =
        std::chrono::system_clock::now().time_since_epoch().count();
    static std::mt19937 engine(seed);

    std::uniform_int_distribution<int> xDist(0, width);
    std::uniform_int_distribution<int> yDist(0, height);

    x = xDist(engine);
    y = yDist(engine);
    z = width;
}

void Starfield::Star::onWindowResize(double widthRatio, double heightRatio) {
    x *= widthRatio;
    y *= heightRatio;
}

void Starfield::Star::update() {}

void Starfield::Star::draw() const { ofDrawCircle(x, y, r); }