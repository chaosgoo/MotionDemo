#include "Vector.h"
Vector::Vector(float x, float y) {
  this->x = x;
  this->y = y;
}
Vector::Vector() {
  this->x = 0;
  this->y = 0;
}
void Vector::mult(float mul) {
  this->x *= mul;
  this->y *= mul;
}