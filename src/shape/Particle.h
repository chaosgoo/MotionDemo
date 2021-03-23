#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "PVector.h"
#include "Vector.h"
#include "component/Component.h"

class Particle : public Component {
 public:
  Vector pos;
  Vector vel;
  Vector acc;

  bool firework;
  int lifespan = 255;
  uint32_t particleColor;
  float hu;
  Particle();
  Particle(float x, float y, bool firework, float hu, uint32_t particleColor);
  void applyForce(Vector force);
  void update();
  void render(TFT_eSprite *eSprite);
  bool done();
};

#endif