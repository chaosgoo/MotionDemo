#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) {
  this->x = x;
  this->y = y;
  this->width = w;
  this->height = h;
}
Rectangle::Rectangle() : Rectangle(0, 0, 0, 0) {}