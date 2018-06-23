/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_BOXCOLLIDERCOMPONENT_H
#define ROGUELIKE_BOXCOLLIDERCOMPONENT_H

#include <ECS/Component.h>
#include "vector.h"

/**
 * It's a collider component that enables collision detection.
 * Could be trigger to only fire an event about collision
 * or could be physical "wall".
 */
class BoxColliderComponent: public ECS::Component<BoxColliderComponent> {
 public:
  BoxColliderComponent(const Vector2 &size, const Vector2 &offset, bool isTrigger)
      : size(size), offset(offset), isTrigger(isTrigger) {}

  Vector2 size;
  Vector2 offset;
  bool isTrigger;
};

#endif //ROGUELIKE_BOXCOLLIDERCOMPONENT_H
