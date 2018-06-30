/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_COLLISIONSYSTEM_H
#define ROGUELIKE_COLLISIONSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include "BoxColliderComponent.h"
#include "TransformComponent.h"

/**
 * Respond to calculate collisions of the all ColliderComponents
 */
class CollisionSystem : public ECS::IteratingSystem<CollisionSystem> {
  LOG_INIT("CollisionSystem");

  std::pair<Vector2, Vector2> coordinates(const ECS::IEntity *entity);

  bool isIntersect(std::pair<Vector2, Vector2> r1, std::pair<Vector2, Vector2> r2);

 public:
  void PreProcessEntity(ECS::IEntity *entity, double dt) override;

  void ProcessEntity(ECS::IEntity *entity, double dt) override;

  const bool FamilyFilter(ECS::IEntity *entity) const override;
};

#endif //ROGUELIKE_COLLISIONSYSTEM_H
