/**
 * Created by Илья Сиганов on 09.06.2018.
 */

#ifndef ROGUELIKE_INPUTSYSTEM_H
#define ROGUELIKE_INPUTSYSTEM_H

#include <ECS/system/IntervalSystem.h>
#include <game/Consts.h>

class InputSystem : public ECS::IntervalSystem<InputSystem> {
  static const uint KEYS_SIZE = 255;
  bool currentKeys[KEYS_SIZE]{};
  LOG_INIT("InputSystem");
  void Clear();

 public:
  explicit InputSystem() : IntervalSystem(IPS) {
    Clear();
  }

  void PreUpdate(double dt) override;

  void PostUpdateInterval(double dt) override;

  // === Keyboard getters ===
  // TODO: may be move to a singleton?

  bool GetButtonDown(unsigned int key);
};

#endif  // ROGUELIKE_INPUTSYSTEM_H
