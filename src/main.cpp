#include <Arduino.h>
#include <Wire.h>

#include "FillScreenDemo.h"
#include "TFT_eSPI.h"

// 显示sprite的内容
TFT_eSPI tft;
// 实际绘制位于sprite
TFT_eSprite sprite = TFT_eSprite(&tft);
// 演示动画的矩形
FillScreenDemo rectCom = FillScreenDemo(0, 56, 20, 20);

void pushToTFT() {
  // 推送到屏幕
  sprite.pushSprite(0, 0);
  // 推送完以后清空当前画面内容
  sprite.fillSprite(TFT_BLACK);
}
void setup() {
  // 初始化屏幕
  tft.init();
  // 旋转屏幕方向，从竖变为横向
  tft.setRotation(1);
  // 清空屏幕内容
  tft.fillScreen(TFT_BLACK);
  // 创建Sprite
  sprite.createSprite(tft.width(), tft.height());
}

void loop() {
  rectCom.update();
  rectCom.render(sprite);

  pushToTFT();
}