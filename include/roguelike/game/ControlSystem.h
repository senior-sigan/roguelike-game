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
  void OnCreated() override {
      inputSystem = GetEngineControl()->GetSystemManager()->Get<InputSystem>();
  }

  void ProcessEntityInterval(ECS::IEntity *entity, double dt) override {
      auto tc = entity->GetComponent<TransformComponent>();
      auto cc = entity->GetComponent<ControlComponent>();

      // TODO: it should be in a component
      int horizontalSpeed = 1;
      int verticalSpeed = 1;

      if (inputSystem->GetButtonDown(cc->up)) {
          tc->position.y -= horizontalSpeed;
      }
      if (inputSystem->GetButtonDown(cc->down)) {
          tc->position.y += horizontalSpeed;
      }
      if (inputSystem->GetButtonDown(cc->right)) {
          tc->position.x += horizontalSpeed;
      }
      if (inputSystem->GetButtonDown(cc->left)) {
          tc->position.x -= horizontalSpeed;
      }
  }

  const bool FamilyFilter(ECS::IEntity *entity) const override {
      return entity->HasComponent<ControlComponent>() && entity->HasComponent<TransformComponent>();
  }
};

#endif //ROGUELIKE_CONTROLSYSTEM_H
