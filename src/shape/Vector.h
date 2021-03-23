#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {
 public:
  float x;
  float y;
  Vector(float x, float y);
  Vector();
  void mult(float mul);
};
#endif