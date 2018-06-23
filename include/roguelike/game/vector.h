/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_VECTOR_H
#define ROGUELIKE_VECTOR_H

struct Vector2 {
  int x;
  int y;
  Vector2(int x, int y) : x(x), y(y) {}

  bool operator==(const Vector2 &other) const {
      return x==other.x && y==other.y;
  }
  bool operator!=(const Vector2 &other) const {
      return !(other==*this);
  }
};

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

#endif //ROGUELIKE_VECTOR_H
