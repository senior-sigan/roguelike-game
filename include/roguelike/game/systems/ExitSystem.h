/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#ifndef ROGUELIKE_EXITSYSTEM_H
#define ROGUELIKE_EXITSYSTEM_H

#include <ECS/system/IntervalSystem.h>
#include <game/systems/InputSystem.h>

class ExitSystem : public ECS::IntervalSystem {
 public:
  explicit ExitSystem() : IntervalSystem(IPS) {}

  void PreUpdateInterval(double dt) override;
};

#endif  // ROGUELIKE_EXITSYSTEM_H
