#pragma once

#include "ofMain.h"

#include <vector>

class TimesTable {
  public:
    TimesTable(std::size_t size);
    void update();
    void draw(int width, int height) const;

    void setNumberOfPoints(std::size_t newSize);
    void setFactor(double factor);

  private:
    std::vector<ofVec2f> mPoints;
    double mFactor = 2.0;
    double mRadiusFactor = 0.9;
};