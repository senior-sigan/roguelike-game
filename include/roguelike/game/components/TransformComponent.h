/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_TRANSFORMCOMPONENT_H
#define ROGUELIKE_TRANSFORMCOMPONENT_H

#include <ECS/Component.h>
#include <core/vector2.h>

class TransformComponent : public ECS::Component<TransformComponent> {
 public:
  explicit TransformComponent(const Core::Vector2 position) : position(position) {}
  Core::Vector2 position;
};

#endif  // ROGUELIKE_TRANSFORMCOMPONENT_H
