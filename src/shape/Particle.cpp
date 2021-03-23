#include "Particle.h"

Particle::Particle(float x, float y, bool firework, float hu,
                   uint32_t particleColor) {
  pos = Vector(x, y);
  this->firework = firework;
  if (firework) {
    vel = Vector(0, random(-6, -2));
  } else {
    PVector p = PVector::random2D();
    vel = Vector(p.x, p.y);
    vel.mult(random(2, 6));
  }
  this->particleColor = particleColor;
  acc = Vector();
  this->hu = hu;
}

Particle::Particle() {}

void Particle::applyForce(Vector force) {
  this->acc.x = force.x;
  this->acc.y = force.y;
}
void Particle::update() {
  if (!firework) {
    this->vel.mult(0.9);
    this->lifespan -= 4;
  }

  this->vel.x += this->acc.x;
  this->vel.y += this->acc.y;

  this->pos.x += this->vel.x;
  this->pos.y += this->vel.y;

  this->acc.mult(0);
}
void Particle::render(TFT_eSprite *eSprite) {
  if (!firework) {
    eSprite->drawPixel(this->pos.x, this->pos.y, particleColor);
  } else {
    eSprite->fillRect(this->pos.x, this->pos.y, 2, 2, particleColor);
  }
}
bool Particle::done() { return lifespan < 0; }