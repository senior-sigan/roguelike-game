/**
 * Created by Илья Сиганов on 11.07.2018.
 */

#ifndef ROGUELIKE_TILERENDERERSYSTEM_H
#define ROGUELIKE_TILERENDERERSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>

class TileRenderingSystem : public ECS::IntervalIteratingSystem {
 public:
  explicit TileRenderingSystem();

  void ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
};

#endif  // ROGUELIKE_TILERENDERERSYSTEM_H
