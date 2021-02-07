#include "RectangleComponent.h"

RectangleComponent::RectangleComponent() : RectangleComponent(0, 0, 0, 0) {}

RectangleComponent::RectangleComponent(int x, int y, int w, int h) {
  _renderRect = Rectangle(x, y, w, h);
  _beginRect = _renderRect;
  _endRect = Rectangle(0, 0, 240, 135);
  animationDone = false;
  animationBeginMillis = millis();
}

void RectangleComponent::render(TFT_eSprite &eSprite) {
  eSprite.fillRect(_renderRect.x, _renderRect.y, _renderRect.width,
                   _renderRect.height, TFT_RED);
}

void RectangleComponent::update() {
  if (!animationDone) {
    animate();
  } else {
    if (reverse) {
      // 从局部变换到满屏幕
      _beginRect = Rectangle(0, 56, 20, 20);
      _endRect = Rectangle(0, 0, 240, 135);
      animationBeginMillis = millis();
    } else {
      // 从满屏幕变换到局部
      _beginRect = Rectangle(0, 0, 240, 135);
      _endRect = Rectangle(0, 56, 20, 20);
      animationBeginMillis = millis();
    }
    // 反转动画
    reverse = !reverse;
    // 设定动画未结束
    animationDone = false;
  }
}

void RectangleComponent::animate() {
  // 判断动画是否结束
  if (millis() - animationBeginMillis > duration) {
    // 若已经超出动画的时间，则认为动画结束
    _renderRect = _endRect;
    animationDone = true;
  } else {
    // 未超出设定的动画，继续执行动画
    _renderRect = CubicEaseInOut(millis() - animationBeginMillis, _beginRect,
                                 _endRect, duration);
  }
}