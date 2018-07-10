/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_COLLISIONSYSTEM_H
#define ROGUELIKE_COLLISIONSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/TransformComponent.h>

/**
 * Respond to calculate collisions of the all ColliderComponents
 */
class CollisionSystem : public ECS::IteratingSystem {
 public:
  void PreProcessEntity(const ECS::IEntityPtr &entity, f64 dt) override;

  void ProcessEntity(const ECS::IEntityPtr &entity, f64 dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
};

#endif  // ROGUELIKE_COLLISIONSYSTEM_H
