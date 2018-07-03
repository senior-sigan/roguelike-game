/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#ifndef ROGUELIKE_EXITSYSTEM_H
#define ROGUELIKE_EXITSYSTEM_H

#include <ECS/system/IntervalSystem.h>
#include "InputSystem.h"

class ExitSystem : public ECS::IntervalSystem<ExitSystem> {
  InputSystem *inputSystem{};
 public:
  ExitSystem() : IntervalSystem(IPS) {}

  void PreUpdate(double dt) override {
      if (inputSystem->GetButtonDown('q')) {
          GetEngineControl()->Stop();
      }
  }

  void OnCreated() override {
      inputSystem = GetEngineControl()->GetSystemManager()->Get<InputSystem>();
  }
};

#endif //ROGUELIKE_EXITSYSTEM_H
