#ifndef RECTANGLE_H_
#define RECTANGLE_H_

class Rectangle {
 public:
  // 矩形X坐标
  int x;
  // 矩形Y坐标
  int y;
  // 矩形宽度
  int width;
  // 矩形高度
  int height;
  Rectangle(int x, int y, int w, int h);
  Rectangle();
};

#endif