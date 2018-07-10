/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_VECTOR_H
#define ROGUELIKE_VECTOR_H

#include "core/types.h"
namespace Core {
struct Vector2 {
  i32 x;
  i32 y;
  Vector2(i32 x, i32 y) : x(x), y(y) {}

  bool operator==(const Vector2 &other) const {
    return x == other.x && y == other.y;
  }
  bool operator!=(const Vector2 &other) const {
    return !(other == *this);
  }

  static Vector2 UP;
  static Vector2 DOWN;
  static Vector2 RIGHT;
  static Vector2 LEFT;
  static Vector2 ZERO;
  static Vector2 ONE;
};

// TODO: create a template....
struct Vector2u {
  u32 x;
  u32 y;
  Vector2u(u32 x, u32 y) : x(x), y(y) {}

  bool operator==(const Vector2u &other) const {
    return x == other.x && y == other.y;
  }
  bool operator!=(const Vector2u &other) const {
    return !(other == *this);
  }

  static Vector2u ONE;
  static Vector2u ZERO;
};
}

#endif  // ROGUELIKE_VECTOR_H
