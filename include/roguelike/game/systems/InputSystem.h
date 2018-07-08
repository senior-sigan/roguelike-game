/**
 * Created by Илья Сиганов on 09.06.2018.
 */

#ifndef ROGUELIKE_INPUTSYSTEM_H
#define ROGUELIKE_INPUTSYSTEM_H

#include <game/Consts.h>
#include <ECS/system/IntervalSystem.h>

class Input {
  friend class InputSystem;
  static const uint8_t KEYS_SIZE = 255;
  bool currentKeys[KEYS_SIZE]{};
  void Clear() {
    for (bool &currentKey : currentKeys) {
      currentKey = false;
    }
  }
  Input() {
    Clear();
  }
  ~Input() = default;

 public:
  bool GetButtonDown(unsigned int key) {
    if (key < KEYS_SIZE) {
      return currentKeys[key];
    } else {
      return false;
    }
  }

  static Input &Instance() {
    static Input instance;
    return instance;
  }
  Input(Input const &) = delete;
  Input &operator=(Input const &) = delete;
};

class InputSystem : public ECS::IntervalSystem {
 public:
  explicit InputSystem() : IntervalSystem(IPS) {}

  void PreUpdate(double dt) override;

  void PostUpdateInterval(double dt) override;
};

typedef std::shared_ptr<InputSystem> InputSystemPtr;

#endif  // ROGUELIKE_INPUTSYSTEM_H
