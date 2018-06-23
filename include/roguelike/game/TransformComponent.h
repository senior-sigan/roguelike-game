/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_TRANSFORMCOMPONENT_H
#define ROGUELIKE_TRANSFORMCOMPONENT_H

#include <ECS/Component.h>
#include <game/vector.h>

class TransformComponent : public ECS::Component<TransformComponent> {
 public:
  explicit TransformComponent(const Vector2 &position) : position(position) {}
  Vector2 position;
};

#endif //ROGUELIKE_TRANSFORMCOMPONENT_H
