#ifndef RECTANGLECOMPONENT_H_
#define RECTANGLECOMPONENT_H_

#include "Rectangle.h"
#include "TFT_eSPI.h"
#include "interploter.h"
class RectangleComponent {
 private:
  // 实际上被渲染的矩形
  Rectangle _renderRect;
  // 动画起始矩形
  Rectangle _beginRect;
  // 动画结束矩形
  Rectangle _endRect;
  // 动画开始的时间
  uint32_t animationBeginMillis;
  // 动画持续时间
  uint16_t duration = 1000;
  // 动画是否完成
  bool animationDone = false;
  // 反转动画
  bool reverse = false;

 public:
  RectangleComponent();
  RectangleComponent(int x, int y, int w, int h);

  void render(TFT_eSprite &eSprite);
  void update();
  void animate();
};

#endif