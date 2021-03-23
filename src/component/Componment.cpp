#include "Component.h"

Component::Component() {}

void Component::render(TFT_eSprite *eSprite) {
  if (!visiable) {
    return;
  }
}

void Component::update() {}

/**
 * @brief 获取该组件宽度
 * @retval 物体宽度
 * */
int Component::getWidth() { return rect.width; };

/**
 * @brief 获取该组件所占高度
 * @retval 物体高度
 * */
int Component::getHeight() { return rect.height; }
