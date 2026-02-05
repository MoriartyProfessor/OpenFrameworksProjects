#include "timestable.h"

#include "../../Utils/scopedMatrix.h"

constexpr double DOUBLE_PI = 2.0 * PI;

TimesTable::TimesTable(std::size_t size) : mPoints(size) {}

void TimesTable::update() {}

void TimesTable::draw(int width, int height) const {
    ScopedMatrix push;
    ofTranslate(width / 2, height / 2);

    double sRadius = mRadiusFactor * std::min(width, height) / 2.0;

    auto drawCentralCircle = [&]() {
        ofNoFill();
        ofSetColor(ofColor::white);
        ofSetCircleResolution(100);
        ofDrawCircle(0, 0, sRadius);
        ofFill();
    };
    drawCentralCircle();

    for (auto i = 0; i < mPoints.size(); ++i) {
        double angle = PI + ofMap(i, 0, mPoints.size(), 0, DOUBLE_PI);
        glm::vec2 start{glm::cos(angle) * sRadius, glm::sin(angle) * sRadius};
        glm::vec2 end{glm::cos(angle * mFactor + PI) * sRadius,
                      glm::sin(angle * mFactor + PI) * sRadius};

        ofDrawLine(start, end);
    }
}

void TimesTable::setNumberOfPoints(std::size_t newSize) {
    mPoints.resize(newSize);
}
void TimesTable::setFactor(double factor) { mFactor = factor; }