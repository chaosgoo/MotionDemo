#include <Arduino.h>
#include <Wire.h>

#include <vector>

#include "FillScreenDemo.h"
#include "TFT_eSPI.h"
#include "component/FireworkComponent/FireworkComponent.h"
#include "component/ScrollNumberComponent/ScrollNumberComponent.h"

// 显示sprite的内容
TFT_eSPI tft;
// 实际绘制位于sprite
TFT_eSprite sprite = TFT_eSprite(&tft);
// 演示动画的矩形
FillScreenDemo rectCom = FillScreenDemo(0, 56, 20, 20);
// 滚动数字
ScrollNumberComponent scrollCom = ScrollNumberComponent('0', 50, 40);
// 烟花
std::vector<FireworkComponent> fireworks;
// 转场
void transcation() {
  rectCom.update();
  rectCom.render(sprite);
}

// 数字滚动
void scrollNumber() {
  // 获取运行的秒数并转换成字符
  char second = '0' + (millis() / 1000) % 10;
  scrollCom.setCh(second);
  scrollCom.update();
  scrollCom.render(&sprite);
}

// 放烟花
void playFireworks() {
  if (random(100) < 5) {
    if (fireworks.size() < 5) {
      fireworks.push_back(FireworkComponent(0, 0));
    }
  }

  for (int i = 0; i < fireworks.size(); i++) {
    fireworks[i].update();
    if (fireworks[i].done()) {
      std::swap(fireworks[i], fireworks[fireworks.size() - 1]);
      fireworks.pop_back();
    }
  }
  for (int i = 0; i < fireworks.size(); i++) {
    fireworks[i].render(&sprite);
  }
}

void pushToTFT() {
  // 推送到屏幕
  sprite.pushSprite(0, 0);
  // 推送完以后清空当前画面内容
  sprite.fillSprite(TFT_BLACK);
}

void setup() {
  Serial.begin(115200);
  // 初始化屏幕
  tft.init();
  // 旋转屏幕方向，从竖变为横向
  tft.setRotation(1);
  // 清空屏幕内容
  tft.fillScreen(TFT_BLACK);
  // 创建Sprite
  sprite.createSprite(tft.width(), tft.height());

  fireworks.push_back(FireworkComponent(0, 0));
}

void loop() {
  // transcation();
  // scrollNumber();
  playFireworks();
  pushToTFT();
}