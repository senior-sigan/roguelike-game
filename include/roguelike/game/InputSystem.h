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
  void PreUpdate(double dt) override {
      int key = getch();
      currentKeys[key] = true;
  };

  void PostUpdateInterval(double dt) override {
      // TODO: We may send events to subscribers.
      for (int i = 0; i < KEYS_SIZE; i++) {
          if (currentKeys[i]) {
              LOG_INFO(i);
          }
      }
      Clear();
  }

  void Clear() {
      for (bool &currentKey : currentKeys) {
          currentKey = false;
      }
  }

  // === Keyboard getters ===
  // TODO: may be move to a singleton?

  bool GetButtonDown(unsigned int key) {
      if (key < KEYS_SIZE) {
          return currentKeys[key];
      } else {
          LOG_WARN("Button key must be between [0..255], but got " << key);
          return false;
      }
  }
};

#endif //ROGUELIKE_INPUTSYSTEM_H
