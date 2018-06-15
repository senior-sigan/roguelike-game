/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALSYSTEM_H
#define ROGUELIKE_INTERVALSYSTEM_H

#include "ECS/FamilyTypeID.h"
#include "ISystem.h"
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
  static const SystemTypeID STATIC_TYPE_ID;
  const double interval{};
  double currentTime{};

  LOG_INIT("IntervalSystem");

  void _PreUpdate(double dt) override {
      PreUpdate(dt);
      currentTime += dt; // Every PRE update increment timer
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
  explicit IntervalSystem(const double interval):interval(interval) {
      currentTime = 0;
  }

  const SystemTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }

  virtual void PreUpdate(double dt) {};
  virtual void Update(double dt) {};
  virtual void PostUpdate(double dt) {};

  virtual void PreUpdateInterval(double dt) {};
  virtual void UpdateInterval(double dt) {};
  virtual void PostUpdateInterval(double dt) {};
};

template<class T>
const ECS::SystemTypeID ECS::IntervalSystem<T>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::ISystem>::Get<T>();

}

#endif //ROGUELIKE_INTERVALSYSTEM_H
