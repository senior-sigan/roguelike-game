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
  const double interval;
  double currentTime;

  void _PreUpdate(double dt) override;

  void _Update(double dt) override;

  void _PostUpdate(double dt) override;

 public:
  explicit IntervalSystem(double interval);
  ~IntervalSystem() override;

  double GetCurrentTime() {
    return currentTime;
  }

  virtual void PreUpdate(double dt) {}
  virtual void Update(double dt) {}
  virtual void PostUpdate(double dt) {}

  virtual void PreUpdateInterval(double dt) {}
  virtual void UpdateInterval(double dt) {}
  virtual void PostUpdateInterval(double dt) {}
};

}

#endif  // ROGUELIKE_INTERVALSYSTEM_H
