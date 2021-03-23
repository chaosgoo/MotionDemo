#if !defined(SCROLLNUMBERCOMPONENT_H_)
#define SCROLLNUMBERCOMPONENT_H_
#include "TFT_eSPI.h"
#include "component/Component.h"
#include "shape/Rectangle.h"
#include "utils/interploter.h"
// 35为Furore28pt7b字体的固定宽度
#define TEXT_WIDTH 35
// 38为Furore28pt7b字体的固定高度
#define TEXT_HEIGHT 38

class ScrollNumberComponent : public Component {
 private:
  // 当前显示字符
  char _ch = 'A';
  // 新字符
  char _newCh = 'A';
  // 动画持续时间
  int16_t duration = 300;
  // 动画启动时间
  int32_t animationBeginMills = 0;
  // 动画中绘制的矩形
  Rectangle charUpdateRenderRect;
  // 起始动画矩形
  Rectangle charUpdateBeginRect;
  // 目标动画矩形
  Rectangle charUpdateEndRect;
  // 字符是否更新完毕
  bool charUpdateDone = false;
  // 每一个数字字符的X偏移量
  uint8_t xOffset[10] = {3, 1, 1, 2, 0, 3, 3, 0, 3, 3};
  /***
   *  需要注意的是:
   *  这里数组中'1'的偏移1和视频中展示的9并不一样
   *  这是因为我修改了字体转换后.h中的内容
   *  您可以查看本仓库中Furore28pt7b.h的133行
   ***/

 public:
  ScrollNumberComponent();
  ScrollNumberComponent(int x, int y, char ch);

  void render(TFT_eSprite *eSprite) override;
  void update() override;
  void animate();

  void setCh(char ch);
};

#endif  // SCROLLNUMBERCOMPONENT_H_
