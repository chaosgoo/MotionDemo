#ifndef FIREWORKCOMPONENT_H_
#define FIREWORKCOMPONENT_H_
#include <cmath>
#include <vector>

#include "TFT_eSPI.h"
#include "shape/Particle.h"
#include "component/Component.h"
#include "utils/utils.h"
class FireworkComponent :public Component{
 private:
  // 原点
  int x;
  int y;
  Vector gravity;
  std::vector<Particle> particles;
  uint32_t fireworkColor;
  bool exploded = false;
  void explode();

 public:
  FireworkComponent();
  FireworkComponent(int x, int y);
  float hu;
  Particle firework;
  void render(TFT_eSprite *eSprite) override;
  void update() override;
  bool done();
};

#endif