#include "interploter.h"

/**
 * @brief CubicEaseIn
 * @param time 经过时间
 * @param begin 起始值
 * @param end 目标值
 * @param duration 总时间
 *
 * @retval 计算结果
 * */
float CubicEaseIn(float time, float begin, float end, float duration) {
  return end * (time /= duration) * time * time + begin;
}

/**
 * @brief CubicEaseOut
 * @param time 经过时间
 * @param begin 起始值
 * @param end 目标值
 * @param duration 总时间
 *
 * @retval 计算结果
 * */
float CubicEaseOut(float time, float begin, float end, float duration) {
  return end * ((time = time / duration - 1) * time * time + 1) + begin;
}

/**
 * @brief CubicEaseInOut
 * @param time 经过时间
 * @param begin 起始值
 * @param end 目标值
 * @param duration 总时间
 *
 * @retval 计算结果
 * */
float CubicEaseInOut(float time, float begin, float end, float duration) {
  if ((time /= duration / 2) < 1) return end / 2 * time * time * time + begin;
  return end / 2 * ((time -= 2) * time * time + 2) + begin;
}

/**
 * @brief ElasticEaseIn
 * @param time 经过时间
 * @param begin 起始值
 * @param end 目标值
 * @param duration 总时间
 *
 * @retval 计算结果
 * */
float ElasticEaseIn(float t, float b, float c, float d) {
  if (t == 0) return b;
  if ((t /= d) == 1) return b + c;
  float p = d * .3f;
  float a = c;
  float s = p / 4;
  float postFix =
      a *
      pow(2, 10 * (t -=
                   1));  // this is a fix, again, with post-increment operators
  return -(postFix * sin((t * d - s) * (2 * PI) / p)) + b;
}
/**
 * @brief ElasticEaseOut
 * @param time 经过时间
 * @param begin 起始值
 * @param end 目标值
 * @param duration 总时间
 *
 * @retval 计算结果
 * */
float ElasticEaseOut(float t, float b, float c, float d) {
  if (t == 0) return b;
  if ((t /= d) == 1) return b + c;
  float p = d * .3f;
  float a = c;
  float s = p / 4;
  return (a * pow(2, -10 * t) * sin((t * d - s) * (2 * PI) / p) + c + b);
}

/**
 * @brief ElasticEaseInOut
 * @param t 经过时间
 * @param b 起始值
 * @param c 目标值
 * @param d 总时间
 *
 * @retval 计算结果
 * */
float ElasticEaseInOut(float t, float b, float c, float d) {
  if (t == 0) return b;
  if ((t /= d / 2) == 2) return b + c;
  float p = d * (.3f * 1.5f);
  float a = c;
  float s = p / 4;

  if (t < 1) {
    float postFix = a * pow(2, 10 * (t -= 1));  // postIncrement is evil
    return -.5f * (postFix * sin((t * d - s) * (2 * PI) / p)) + b;
  }
  float postFix = a * pow(2, -10 * (t -= 1));  // postIncrement is evil
  return postFix * sin((t * d - s) * (2 * PI) / p) * .5f + c + b;
}

/**
 * @brief CubicEaseInOut
 * @param t 经过时间
 * @param b 起始值
 * @param c 目标值
 * @param d 总时间
 *
 * @retval 计算结果
 * */
Rectangle CubicEaseInOut(float time, Rectangle begin, Rectangle end,
                         float duration) {
  return Rectangle(
      begin.x == end.x ? begin.x
      : begin.x < end.x
          ? CubicEaseInOut(time, begin.x, end.x - begin.x, duration)
          : CubicEaseInOut(duration - time, end.x, begin.x - end.x, duration),
      begin.y == end.y ? begin.y
      : begin.y < end.y
          ? CubicEaseInOut(time, begin.y, end.y - begin.y, duration)
          : CubicEaseInOut(duration - time, end.y, begin.y - end.y, duration),
      begin.width == end.width ? begin.width
      : begin.width < end.width
          ? CubicEaseInOut(time, begin.width, end.width - begin.width, duration)
          : CubicEaseInOut(duration - time, end.width, begin.width - end.width,
                           duration),
      begin.height == end.height ? begin.height
      : begin.height < end.height
          ? CubicEaseInOut(time, begin.height, end.height - begin.height,
                           duration)
          : CubicEaseInOut(duration - time, end.height,
                           begin.height - end.height, duration));
}

/**
 * @brief ElasticEaseInOut
 * @param t 经过时间
 * @param b 起始值
 * @param c 目标值
 * @param d 总时间
 *
 * @retval 计算结果
 * */
Rectangle ElasticEaseInOut(float time, Rectangle begin, Rectangle end,
                           float duration) {
  return Rectangle(
      begin.x == end.x ? begin.x
      : begin.x < end.x
          ? ElasticEaseInOut(time, begin.x, end.x - begin.x, duration)
          : ElasticEaseInOut(duration - time, end.x, begin.x - end.x, duration),
      begin.y == end.y ? begin.y
      : begin.y < end.y
          ? ElasticEaseInOut(time, begin.y, end.y - begin.y, duration)
          : ElasticEaseInOut(duration - time, end.y, begin.y - end.y, duration),
      begin.width == end.width ? begin.width
      : begin.width < end.width
          ? ElasticEaseInOut(time, begin.width, end.width - begin.width,
                             duration)
          : ElasticEaseInOut(duration - time, end.width,
                             begin.width - end.width, duration),
      begin.height == end.height ? begin.height
      : begin.height < end.height
          ? ElasticEaseInOut(time, begin.height, end.height - begin.height,
                             duration)
          : ElasticEaseInOut(duration - time, end.height,
                             begin.height - end.height, duration));
}
