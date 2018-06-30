/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_COLLISIONSYSTEM_H
#define ROGUELIKE_COLLISIONSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include "game/components/BoxColliderComponent.h"
#include "game/components/TransformComponent.h"

/**
 * Respond to calculate collisions of the all ColliderComponents
 */
class CollisionSystem : public ECS::IteratingSystem<CollisionSystem> {
  LOG_INIT("CollisionSystem");

  std::pair<Core::Vector2, Core::Vector2> coordinates(const ECS::IEntity *entity);

  bool isIntersect(std::pair<Core::Vector2, Core::Vector2> r1, std::pair<Core::Vector2, Core::Vector2> r2);

 public:
  void PreProcessEntity(ECS::IEntity *entity, double dt) override;

  void ProcessEntity(ECS::IEntity *entity, double dt) override;

  const bool FamilyFilter(ECS::IEntity *entity) const override;
};

#endif //ROGUELIKE_COLLISIONSYSTEM_H
