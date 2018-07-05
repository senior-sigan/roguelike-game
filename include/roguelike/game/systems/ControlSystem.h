/**
 * Created by Илья Сиганов on 16.06.2018.
 */

#ifndef ROGUELIKE_CONTROLSYSTEM_H
#define ROGUELIKE_CONTROLSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include <ECS/system/SystemManager.h>
#include <game/components/ControlComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/InputSystem.h>
class ControlSystem : public ECS::IntervalIteratingSystem<ControlSystem> {
  InputSystem *inputSystem{};
  LOG_INIT("ControlSystem");

 public:
  explicit ControlSystem() : IntervalIteratingSystem(IPS) {}

  void OnCreated() override;

  void ProcessEntityInterval(const ECS::IEntityPtr &entity, double dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
};

#endif  // ROGUELIKE_CONTROLSYSTEM_H
