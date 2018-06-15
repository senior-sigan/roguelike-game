/**
 * Created by Илья Сиганов on 09.06.2018.
 */

#ifndef ROGUELIKE_INPUTSYSTEM_H
#define ROGUELIKE_INPUTSYSTEM_H

#include <ncurses.h>
#include <ECS/system/IntervalSystem.h>

class InputSystem : public ECS::IntervalSystem<InputSystem> {
  const double FPS = 1.0/25.0; // it means 25 FPS
  static const int KEYS_SIZE = 255;
  bool currentKeys[KEYS_SIZE]{};
  LOG_INIT("InputSystem");
 public:
  explicit InputSystem() : IntervalSystem(FPS) {
      Clear();
  }
  void PreUpdate(double dt) override {
      int key = getch();
      currentKeys[key] = true;
  };

  void PostUpdateInterval(double dt) override {
      Clear();
  }

  void Clear() {
      for (bool &currentKey : currentKeys) {
          currentKey = false;
      }
  }
};

#endif //ROGUELIKE_INPUTSYSTEM_H
