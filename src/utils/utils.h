#ifndef LIB_UTILS_H_
#define LIB_UTILS_H_

#include <stdint.h>

#include "EEPROM.h"
#include "TFT_eSPI.h"
#include "common_macro.h"
#include "shape/Rectangle.h"
int checkSum(const char* src, int length);
int c2i(char ch);

int getTextWidth(const char* text, TFT_eSprite& sprite);

int getTextWidth(const char* text, TFT_eSprite* sprite);

byte EEreadValue(int address);
String paddingText(String text, int length);
String number2words(int number);
String time2words(int number);
int calcSingleLevel(int rssi);
uint32_t blend(uint32_t topColor, uint32_t bottomColor);

#endif