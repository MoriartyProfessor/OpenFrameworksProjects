#include "ofMain.h"

#include <vector>

class Flock;

class Boid {
  public:
    Boid();
    Boid(ofVec2f pos, ofVec2f vel, ofVec2f acc);

    void update(const std::vector<Boid> &boids, size_t ind);
    void draw(const size_t width, const size_t height) const;

  private:
    ofVec2f mPosition;
    ofVec2f mVelocity;
    ofVec2f mAccelaration;

    struct Parameters {
        double separationStrength{};
        double alignmentStrength{};
        double cohesionStrength{};
        double flockRadius{};
    };

    static Parameters sParameters;

    friend Flock;
};