/*
 * Original
 * https://github.com/jesusgollonet/ofpennereasing
 */
#ifndef INTERPLOTER_H_
#define INTERPLOTER_H_

#include <math.h>

#include "shape/Rectangle.h"

#ifndef PI
#define PI 3.14159265
#endif
float CubicEaseIn(float time, float begin, float end, float duration);
float CubicEaseOut(float time, float begin, float end, float duration);
float CubicEaseInOut(float time, float begin, float end, float duration);
Rectangle CubicEaseInOut(float time, Rectangle begin, Rectangle end,
                         float duration);

float ElasticEaseIn(float t, float b, float c, float d);
float ElasticEaseOut(float t, float b, float c, float d);
float ElasticEaseInOut(float t, float b, float c, float d);
Rectangle ElasticEaseInOut(float time, Rectangle begin, Rectangle end,
                           float duration);
#endif