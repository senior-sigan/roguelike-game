/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_TRANSFORMCOMPONENT_H
#define ROGUELIKE_TRANSFORMCOMPONENT_H

#include <ECS/IComponent.h>
#include <core/vector2.h>

class TransformComponent : public ECS::IComponent {
 public:
  explicit TransformComponent(const Core::Vector2 &position) : position(position) {}
  Core::Vector2 position;
};

typedef std::shared_ptr<TransformComponent> TransformComponentPtr;

#endif  // ROGUELIKE_TRANSFORMCOMPONENT_H
