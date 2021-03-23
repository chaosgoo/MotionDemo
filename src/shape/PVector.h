#ifndef PVECTOR_H_
#define PVECTOR_H_
#include "component/Component.h"

class PVector {
 public:
  float x;
  float y;
  PVector(float x, float y);
  PVector();
  static PVector random2D();
};

#endif