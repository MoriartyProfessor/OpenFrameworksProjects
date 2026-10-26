#include <vector>

#include "boid.hpp"

class Flock {
  public:
    Flock(const size_t boidCnt);

    void resize(const size_t boidCnt);

    void setSeparationStrength(double);
    void setAlignmentStrength(double);
    void setCohesionStrength(double);
    void setFlockRadius(double);

    void update();
    void draw(const size_t width, const size_t height);

  private:
    std::vector<Boid> mBoidsFront;
    std::vector<Boid> mBoidsBack;
};