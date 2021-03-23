#include "ScrollNumberComponent.h"
ScrollNumberComponent::ScrollNumberComponent() {}

ScrollNumberComponent::ScrollNumberComponent(int x, int y, char ch) {
  this->_ch = ch;
  this->rect = Rectangle(x, y, TEXT_WIDTH, TEXT_HEIGHT);
}

void ScrollNumberComponent::render(TFT_eSprite *eSprite) {
  eSprite->setFreeFont(&Furore28pt7b);
  // 替换动画进行中，新旧字符同时绘制
  if (!charUpdateDone) {
    eSprite->drawChar(_ch, rect.x,
                     rect.y + charUpdateRenderRect.height + TEXT_HEIGHT);
    eSprite->drawChar(_newCh, rect.x, rect.y + charUpdateRenderRect.height);
    eSprite->fillRect(rect.x + xOffset[_newCh - '0'], rect.y - rect.height,
                     rect.width, rect.height + 2, TFT_BLACK);
    eSprite->fillRect(rect.x + xOffset[_ch - '0'], rect.y + rect.height + 2,
                     rect.width, rect.height + 2, TFT_BLACK);
  } else {
    // 替换动画结束，只绘制新字符
    eSprite->drawChar(_ch, rect.x, rect.y + charUpdateRenderRect.height);
    eSprite->fillRect(rect.x + xOffset[_ch - '0'], rect.y - rect.height,
                     rect.width, rect.height + 2, TFT_BLACK);
  }
}

void ScrollNumberComponent::update() {
  if (!charUpdateDone) {
    animate();
  }
}

void ScrollNumberComponent::animate() {
  if (millis() - animationBeginMills > duration) {
    // 动画结束
    charUpdateDone = true;
    charUpdateRenderRect = charUpdateEndRect;
    _ch = _newCh;
  } else {
    charUpdateRenderRect =
        CubicEaseInOut(millis() - animationBeginMills, charUpdateBeginRect,
                       charUpdateEndRect, duration);
  }
}

void ScrollNumberComponent::setCh(char ch) {
  // 检查字符是否变化
  if (ch != _ch && charUpdateDone) {
    // 发生变化则准备执行更新动画
    charUpdateBeginRect = Rectangle(rect.x, rect.y, TEXT_WIDTH, 1);
    charUpdateEndRect = Rectangle(rect.x, rect.y, TEXT_WIDTH, TEXT_HEIGHT + 2);
    _newCh = ch;
    charUpdateDone = false;
    animationBeginMills = millis();
  }
}