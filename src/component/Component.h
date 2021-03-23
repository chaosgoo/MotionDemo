//
// Created by gyc84 on 2020/12/7.
//

#ifndef COMPONENT_HPP
#define COMPONENT_HPP
#include "common_macro.h"
#include "shape/Rectangle.h"
#include <TFT_eSPI.h>
/**
 * @brief 基础组件 \n(换行)
 * 具有尺寸信息rect \n
 * 以及渲染visiable
 */
class Component {
 public:
  Rectangle rect;
  bool visiable = true;
  Component();
  // 不可见对象不渲染
  virtual void render(TFT_eSprite *eSprite);
  virtual void update();
  int getWidth();
  int getHeight();

  virtual ~Component() = default;
};

#endif  // TINYMONITOR_COMPONENT_HPP
