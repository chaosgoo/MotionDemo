#include "utils.h"

/**
 * @brief 计算16校验和计算
 * @param src 待校验内容
 * @param length 待校验内容长度
 * @retval 校验和
 * */
int checkSum(const char *src, int length) {
  int16_t sum = 0;
  for (int i = 0; i < length; i++) {
    sum += src[i];
  }
  sum = (sum & 0xff) + (sum >> 16);
  return ~sum & 0xff;
}

/**
 * @brief 16进制字符转int
 * @param ch 待转换内容
 * @retval 校验和
 * */
// https://www.cnblogs.com/lidabo/p/3995055.html
int c2i(char ch) {
  // 如果是数字，则用数字的ASCII码减去48, 如果ch = '2' ,则 '2' - 48 = 2
  if (isdigit(ch)) return ch - 48;

  // 如果是字母，但不是A~F,a~f则返回
  if (ch < 'A' || (ch > 'F' && ch < 'a') || ch > 'z') return -1;

  // 如果是大写字母，则用数字的ASCII码减去55, 如果ch = 'A' ,则 'A' - 55 = 10
  // 如果是小写字母，则用数字的ASCII码减去87, 如果ch = 'a' ,则 'a' - 87 = 10
  if (isalpha(ch)) return isupper(ch) ? ch - 55 : ch - 87;

  return -1;
}

int getTextWidth(const char *text, TFT_eSprite &sprite) {
  return sprite.textWidth(text);
}

int getTextWidth(const char *text, TFT_eSprite *sprite) {
  return sprite->textWidth(text);
}

// 读取值
byte EEreadValue(int address) { return EEPROM.readByte(address); }


/**
 * @brief 颜色混合
 * @param topColor 顶层颜色 32位RGBA格式
 * @param bottomColor 底层颜色 32位RGBA格式
 * @return 混合结果
 **/
uint32_t blend(uint32_t topColor, uint32_t bottomColor) {
  float a1 = (topColor & 0xFF);
  float a2 = (bottomColor & 0xFF) - (a1 * (bottomColor & 0xFF)) / 255.0;
  float a = a1 + a2;
  int R = (a1 * (topColor >> 24) + a2 * (bottomColor >> 24)) / a;
  int G =
      (a1 * ((topColor >> 16) & 0xff) + a2 * ((bottomColor >> 16) & 0xff)) / a;
  int B =
      (a1 * ((topColor >> 8) & 0xff) + a2 * ((bottomColor >> 8) & 0xff)) / a;
  int A = a;
  return (R << 24) | (G << 16) | (B << 8) | A;
}

/**
 * @brief 文字宽度填充
 * @param text 待填充文字
 * @param width 目标宽度
 * @return 混合结果
 **/
String paddingText(String text, int length) {
  while (text.length() < length) {
    text = "0" + text;
  }
  return text;
}

/**
 * @brief 数字转文字
 * @param number 数字
 * @return 文字时间
 **/
String number2words(int number) {
  switch (number) {
    case 0:
      return "O";
    case 1:
      return "ONE";
    case 2:
      return "TWO";
    case 3:
      return "THREE";
    case 4:
      return "FOUR";
    case 5:
      return "FIVE";
    case 6:
      return "SIX";
    case 7:
      return "SEVEN";
    case 8:
      return "EIGHT";
    case 9:
      return "NINE";
    case 10:
      return "TEN";
    case 11:
      return "ELEVEN";
    case 12:
      return "TWELVE";
    case 13:
      return "THIRTEEN";
    case 14:
      return "FORTEEN";
    case 15:
      return "FIFTEEN";
    case 16:
      return "SIXTEEN";
    case 17:
      return "SEVENTEEN";
    case 18:
      return "EIGHTEEN";
    case 19:
      return "NINETEEN";
    case 20:
      return "TWENTY";
    case 30:
      return "THIRTY";
    case 40:
      return "FORTY";
    case 50:
      return "FIFTY";
  }
}


/**
 * @brief 计算WiFi信号强度
 * @param rssi RSSI值
 * @return 信号等级 越大越好
 **/
int calcSingleLevel(int rssi) {
  if (rssi >= -55)
    return 4;
  else if (rssi >= -66 && rssi < -55)
    return 3;
  else if (rssi >= -77 && rssi < -67)
    return 2;
  else if (rssi >= -88 && rssi < -78)
    return 1;
  else if (rssi < -88)
    return 0;
}