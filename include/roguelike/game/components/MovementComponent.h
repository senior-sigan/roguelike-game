/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_MOVEMENTCOMPONENT_H
#define ROGUELIKE_MOVEMENTCOMPONENT_H

#include <ECS/Component.h>
#include <core/vector2.h>
class MovementComponent : public ECS::Component<MovementComponent> {
 public:
  MovementComponent(const Core::Vector2 speed, const Core::Vector2 slowDownSpeed)
      : speed(speed), slowDownSpeed(slowDownSpeed) {}

  Core::Vector2 direction = Core::Vector2::ZERO;

  // It stores an entity speed that could be applied
  Core::Vector2 speed;

  // It stores an entity speed to slow down. So when entity stops.
  Core::Vector2 slowDownSpeed;

  // It stores the force that should be applied
  Core::Vector2 force = Core::Vector2::ZERO;
};

typedef std::shared_ptr<MovementComponent> MovementComponentPtr;

#endif  // ROGUELIKE_MOVEMENTCOMPONENT_H
