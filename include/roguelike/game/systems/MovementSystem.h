/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_MOVEMENTSYSTEM_H
#define ROGUELIKE_MOVEMENTSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include <game/components/MovementComponent.h>
#include <game/components/TransformComponent.h>
class MovementSystem : public ECS::IteratingSystem<MovementSystem> {
 public:
  void ProcessEntity(ECS::IEntity *entity, double dt) override;

  const bool FamilyFilter(ECS::IEntity const *entity) const override;
};

#endif //ROGUELIKE_MOVEMENTSYSTEM_H
