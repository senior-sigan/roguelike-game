/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALITERATINGSYSTEM_H
#define ROGUELIKE_INTERVALITERATINGSYSTEM_H

#include <ECS/EntityManager.h>
#include "ECS/FamilyTypeID.h"
#include "ISystem.h"
namespace ECS {

/**
 * It's a combination of interval and iterating systems.
 *
 * @tparam T
 */
template<class T>
class IntervalIteratingSystem : public ISystem {
  friend class SystemManager;
  static const SystemTypeID STATIC_TYPE_ID;
  const double interval{};
  double currentTime{};

  template<class T>
  void PreUpdate(double dt) {
      currentTime += dt; // Every PRE update increment timer
      if (currentTime >= interval) {
          PreUpdateInterval(currentTime);
      }
  }
  template<class T>
  void Update(double dt) {
      if (currentTime >= interval) {
          UpdateInterval(currentTime);
      }
  }
  template<class T>
  void PostUpdate(double dt) {
      if (currentTime >= interval) {
          PostUpdateInterval(currentTime);
          currentTime -= interval;  // Every POST update decrement timer
      }
  }

  void PreUpdateInterval(double dt) {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PreProcessEntity(entity.second, dt);
          }
      }
  }
  void UpdateInterval(double dt) {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              ProcessEntity(entity.second, dt);
          }
      }
  }
  void PostUpdateInterval(double dt) {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PostProcessEntity(entity.second, dt);
          }
      }
  }

 public:
  template<class T>
  explicit IntervalIteratingSystem(const double interval):interval(interval) {
      currentTime = 0;
  }

  const SystemTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }

  virtual void PreProcessEntity(IEntity *entity, double dt) {};
  virtual void ProcessEntity(IEntity *entity, double dt) {};
  virtual void PostProcessEntity(IEntity *entity, double dt) {};

  /**
   * Filter and pass only IEntities that satisfy the predicate.
   * @return true if satisfy and false otherwise.
   */
  virtual const bool FamilyFilter(IEntity *entity) const {
      return false;
  };
};

template<class T>
const ECS::SystemTypeID
    ECS::IntervalIteratingSystem<T>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::ISystem>::Get<T>();

}

#endif //ROGUELIKE_INTERVALITERATINGSYSTEM_H
