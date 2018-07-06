/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#ifndef ROGUELIKE_EXITSYSTEM_H
#define ROGUELIKE_EXITSYSTEM_H

#include <ECS/system/IntervalSystem.h>
#include <game/systems/InputSystem.h>

class ExitSystem : public ECS::IntervalSystem<ExitSystem> {
 public:
  explicit ExitSystem() : IntervalSystem(IPS) {}

  void PreUpdateInterval(double dt) override {
    auto inputSystem = GetEngineControl()->GetSystemManager()->Get<InputSystem>();

    if (inputSystem->GetButtonDown('q')) {
      GetEngineControl()->Stop();
    }
  }
};

#endif  // ROGUELIKE_EXITSYSTEM_H
