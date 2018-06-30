/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#ifndef ROGUELIKE_VECTOR2F_H
#define ROGUELIKE_VECTOR2F_H

#include <math.h>

namespace Core {
struct Vector2f {
  const float eps = 0.00000001;
  float x;
  float y;
  Vector2f(float x, float y) : x(x), y(y) {}

  bool operator==(const Vector2f &other) const {
      return abs(x - other.x) < eps && abs(y - other.y) < eps;
  }
  bool operator!=(const Vector2f &other) const {
      return !(other==*this);
  }
};
}
#endif //ROGUELIKE_VECTOR2F_H
