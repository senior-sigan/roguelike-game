/**
 * Created by Илья Сиганов on 16.06.2018.
 */

#ifndef ROGUELIKE_CONTROLSYSTEM_H
#define ROGUELIKE_CONTROLSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include "ControlComponent.h"
#include "TransformComponent.h"
#include "InputSystem.h"
#include "ECS/system/SystemManager.h"
class ControlSystem : public ECS::IntervalIteratingSystem<ControlSystem> {
  InputSystem *inputSystem{};
  LOG_INIT("ControlSystem");
 public:
  explicit ControlSystem() : IntervalIteratingSystem(IPS) {}

  void OnCreated() override;

  void ProcessEntityInterval(ECS::IEntity *entity, double dt) override;

  const bool FamilyFilter(ECS::IEntity *entity) const override;
};

#endif //ROGUELIKE_CONTROLSYSTEM_H
