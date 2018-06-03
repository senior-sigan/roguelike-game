/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_TRANSFORMCOMPONENT_H
#define ROGUELIKE_TRANSFORMCOMPONENT_H

#include <ECS/Component.h>

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

class TransformComponent : public ECS::Component<TransformComponent> {
 public:
  explicit TransformComponent(const Vector2 &position) : position(position) {}
  Vector2 position;
};

#endif //ROGUELIKE_TRANSFORMCOMPONENT_H
