/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_ITERATINGSYSTEM_H
#define ROGUELIKE_ITERATINGSYSTEM_H

#include <ECS/EntityManager.h>
#include "ECS/FamilyTypeID.h"
#include "ISystem.h"
namespace ECS {
template<class T>
class IteratingSystem : public ISystem {
  friend class SystemManager;
  static const SystemTypeID STATIC_TYPE_ID;
 public:
  const SystemTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }

  void PreUpdate(double dt) override {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PreProcessEntity(entity.second, dt);
          }
      }
  }
  void Update(double dt) override {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              ProcessEntity(entity.second, dt);
          }
      }
  }
  void PostUpdate(double dt) override {
      for (auto entity : GetEntityManager()->container) {
          if (FamilyFilter(entity.second)) {
              PostProcessEntity(entity.second, dt);
          }
      }
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
const ECS::SystemTypeID ECS::IteratingSystem<T>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::ISystem>::Get<T>();
}
#endif //ROGUELIKE_ITERATINGSYSTEM_H