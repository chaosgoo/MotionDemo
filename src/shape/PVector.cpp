#include "PVector.h"

#include <math.h>

PVector::PVector(float x, float y) {
  this->x = x;
  this->y = y;
}
PVector::PVector() {
  this->x = 0;
  this->y = 0;
}
PVector PVector::random2D() {
  int angle = random(360);
  return PVector(sin(angle * PI / 180.0), cos(angle * PI / 180.0));
}