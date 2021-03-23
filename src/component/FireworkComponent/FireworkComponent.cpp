#include "FireworkComponent.h"

FireworkComponent::FireworkComponent() : FireworkComponent(0, 0) {}

FireworkComponent::FireworkComponent(int x, int y) {
  fireworkColor =
      (random(255) << 24) | (random(255) << 16) | (random(255) << 8);
  this->x = x;
  this->y = y;
  this->hu = random(255);
  this->firework = Particle(40 + random(200), 135 + random(100), true, this->hu,
                            fireworkColor);
  this->exploded = false;
  this->gravity = Vector(0, 0.1f);
}

void FireworkComponent::render(TFT_eSprite *eSprite) {
  if (!exploded) {
    firework.render(eSprite);
  } else {
    for (Particle particle : particles) {
      particle.render(eSprite);
    }
  }
}

void FireworkComponent::update() {
  if (!exploded) {
    firework.applyForce(gravity);
    firework.update();
    if (firework.vel.y >= 0) {
      exploded = true;
      explode();
    }
  } else {
    for (int i = 0; i < particles.size(); i++) {
      particles[i].applyForce(gravity);
      particles[i].update();
      if (particles[i].done()) {
        std::swap(particles[i], particles[particles.size() - 1]);
        particles.pop_back();
      }
    }
  }
}

bool FireworkComponent::done() { return exploded && particles.size() == 0; }

void FireworkComponent::explode() {
  for (int i = 0; i < 50; i++) {
    Particle p =
        Particle(firework.pos.x, firework.pos.y, false, hu, fireworkColor);
    particles.push_back(p);
  }
}