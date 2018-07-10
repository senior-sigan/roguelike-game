/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_RENDERINGSYSTEM_H
#define ROGUELIKE_RENDERINGSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include <ECS/system/System.h>

class RenderingSystem : public ECS::IntervalIteratingSystem {
  const ECS::EntityID targetID;
 public:
  // TODO: actually rendering system should get this target from the engine by some tag.
  // We would like to add as many rener target as we want without modifying this constructor
  // Maybe rendering system should select groups of renderabel objects and rendering target
  explicit RenderingSystem(const ECS::EntityID targetID);

  void PostUpdateInterval(f64 dt) override;
  void ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
  void OnCreated() override;
  void OnDestroy() override;
};

#endif  // ROGUELIKE_RENDERINGSYSTEM_H
