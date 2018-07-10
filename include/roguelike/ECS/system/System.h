/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_SYSTEM_H
#define ROGUELIKE_SYSTEM_H

#include <ECS/system/ISystem.h>
#include <ECS/system/IUpdate.h>
namespace ECS {

/**
 * General System. Update commands will be called on every world update.
 * If you need iterates over Entities, use IteratingSystem.
 */
class System : public ISystem {
  friend class SystemManager;

 private:
  void _PreUpdate(f64 dt) override {
    PreUpdate(dt);
  }
  void _Update(f64 dt) override {
    Update(dt);
  }
  void _PostUpdate(f64 dt) override {
    PostUpdate(dt);
  }

 public:
  virtual void PreUpdate(f64 dt) {}
  virtual void Update(f64 dt) {}
  virtual void PostUpdate(f64 dt) {}
};

}

#endif  // ROGUELIKE_SYSTEM_H
