/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALSYSTEM_H
#define ROGUELIKE_INTERVALSYSTEM_H

#include <ECS/system/ISystem.h>
namespace ECS {

/**
 * Update commands will be called on every world update, but after given interval.
 * If you need iterates over Entities, use IteratingSystem.
 */
class IntervalSystem : public ISystem {
  friend class SystemManager;
  const f64 interval;
  f64 currentTime;

  void _PreUpdate(f64 dt) override;

  void _Update(f64 dt) override;

  void _PostUpdate(f64 dt) override;

 public:
  explicit IntervalSystem(f64 interval);
  ~IntervalSystem() override;

  f64 GetCurrentTime() {
    return currentTime;
  }

  virtual void PreUpdate(f64 dt) {}
  virtual void Update(f64 dt) {}
  virtual void PostUpdate(f64 dt) {}

  virtual void PreUpdateInterval(f64 dt) {}
  virtual void UpdateInterval(f64 dt) {}
  virtual void PostUpdateInterval(f64 dt) {}
};

}

#endif  // ROGUELIKE_INTERVALSYSTEM_H
