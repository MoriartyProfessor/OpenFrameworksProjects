#pragma once

#include <vector>

class Starfield {
  public:
    Starfield(std::size_t size);
    void resize(std::size_t newSize);
    void update();
    void draw(int width, int height) const;
    void setCameraSpeed(double cameraSpeed);

  private:
    class Star {
      public:
        Star();
        void update(double cameraSpeed);
        void draw(int width, int height) const;

      private:
        double x = 0;
        double y = 0;
        double z = 0;
        double r = 0;
    };
    std::vector<Star> mStars;
    std::size_t mSize;
    double mCameraSpeed = 0.01;
};