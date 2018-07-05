/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_BOXCOLLIDERCOMPONENT_H
#define ROGUELIKE_BOXCOLLIDERCOMPONENT_H

#include <ECS/Component.h>
#include <ECS/IEntity.h>
#include <core/vector2.h>
#include <set>

/**
 * It's a collider component that enables collision detection.
 * Could be trigger to only fire an event about collision
 * or could be physical "wall".
 */
class BoxColliderComponent : public ECS::Component<BoxColliderComponent> {
  std::set<const ECS::IEntity *> collisions{};

 public:
  explicit BoxColliderComponent(const Core::Vector2 size, const Core::Vector2 offset, bool isTrigger = false,
                                bool isMovable = true)
      : size(size), offset(offset), isTrigger(isTrigger), isMovable(isMovable) {}

  Core::Vector2 size;
  Core::Vector2 offset;
  bool isTrigger;
  bool isMovable;

  const std::set<const ECS::IEntity *> GetCollisions() const {
    return collisions;
  }

  void Collide(const ECS::IEntity *entity) {
    collisions.emplace(entity);
  }

  void Clear() {
    collisions.clear();
  }
};

#endif  // ROGUELIKE_BOXCOLLIDERCOMPONENT_H
