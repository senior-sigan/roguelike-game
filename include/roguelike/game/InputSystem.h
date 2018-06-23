/**
 * Created by Илья Сиганов on 09.06.2018.
 */

#ifndef ROGUELIKE_INPUTSYSTEM_H
#define ROGUELIKE_INPUTSYSTEM_H

#include <ncurses.h>
#include <ECS/system/IntervalSystem.h>
#include "Consts.h"

class InputSystem : public ECS::IntervalSystem<InputSystem> {
  static const unsigned int KEYS_SIZE = 255;
  bool currentKeys[KEYS_SIZE]{};
  LOG_INIT("InputSystem");
 public:
  explicit InputSystem() : IntervalSystem(IPS) {
      Clear();
  }

  void PreUpdate(double dt) override;;

  void PostUpdateInterval(double dt) override;

  void Clear();

  // === Keyboard getters ===
  // TODO: may be move to a singleton?

  bool GetButtonDown(unsigned int key);
};

#endif //ROGUELIKE_INPUTSYSTEM_H
