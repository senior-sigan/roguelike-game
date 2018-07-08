/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALSYSTEM_H
#define ROGUELIKE_INTERVALSYSTEM_H

#include <ECS/FamilyTypeID.h>
#include <ECS/system/ISystem.h>
namespace ECS {

/**
 * Update commands will be called on every world update, but after given interval.
 * If you need iterates over Entities, use IteratingSystem.
 *
 * @tparam T
 */
template<class T>
class IntervalSystem : public ISystem {
  friend class SystemManager;
  const double interval;
  double currentTime;
  bool OFFSET = false;  // TODO: MAGIC IS HERE. DO NOT REMOVE, OTHERWAISE BUUUUM!!!!!!!!

  void _PreUpdate(double dt) override {
    PreUpdate(dt);
    if (currentTime < 0) currentTime = 0;
    if (dt > 0) currentTime += dt;  // Every PRE update increment timer
    if (currentTime >= interval) {
      PreUpdateInterval(currentTime);
    }
  }

  void _Update(double dt) override {
    Update(dt);
    if (currentTime >= interval) {
      UpdateInterval(currentTime);
    }
  }

  void _PostUpdate(double dt) override {
    PostUpdate(dt);
    if (currentTime >= interval) {
      PostUpdateInterval(currentTime);
      currentTime -= interval;  // Every POST update decrement timer
    }
  }

 public:
  explicit IntervalSystem(const double interval) : interval(interval) {
    currentTime = 0;
  }

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
