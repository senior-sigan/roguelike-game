/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_MOVEMENTSYSTEM_H
#define ROGUELIKE_MOVEMENTSYSTEM_H

#include <ECS/system/IteratingSystem.h>
class MovementSystem : public ECS::IteratingSystem {
 public:
  void ProcessEntity(const ECS::IEntityPtr &entity, f64 dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
};

#endif  // ROGUELIKE_MOVEMENTSYSTEM_H
