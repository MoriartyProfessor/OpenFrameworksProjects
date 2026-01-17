#pragma once

#include <vector>

class Starfield {
  public:
    Starfield(int width, int height, std::size_t size);
    void resize(std::size_t newSize);
    void onWindowResize(int width, int height);
    void update();
    void draw() const;

  private:
    class Star {
      public:
        Star(int width, int height);
        void onWindowResize(double widthRatio, double heightRatio);
        void update();
        void draw() const;

      private:
        double x = 0;
        double y = 0;
        double z = 0;
        int r = 8;
    };
    std::vector<Star> mStars;
    int mWidth;
    int mHeight;
    std::size_t mSize;
};