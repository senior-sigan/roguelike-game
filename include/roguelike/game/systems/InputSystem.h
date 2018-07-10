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
  void Clear();
  Input() {
    Clear();
  }
  ~Input() = default;

 public:
  bool GetButtonDown(u32 key);

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

  void PreUpdate(f64 dt) override;

  void PostUpdateInterval(f64 dt) override;
};

typedef std::shared_ptr<InputSystem> InputSystemPtr;

#endif  // ROGUELIKE_INPUTSYSTEM_H
