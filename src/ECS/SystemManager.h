/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_SYSTEMMANAGER_H
#define ROGUELIKE_SYSTEMMANAGER_H

#include <map>
#include "Platform.h"
#include "ISystem.h"
namespace ECS {
class SystemManager {
  friend class Engine;

  std::map<SystemTypeID, ISystem *> container;
  EntityManager *entityManager;

  void Update(float delta) {
      auto i = 0;
      for (auto entity : entityManager->container) {
          for (std::pair<SystemTypeID, ISystem *> system: container) {
              if (system.second->FamilyFilter(entity.second)) {
                  system.second->Update(entity.second, delta);
              }
          }
      }
  };

 public:
  SystemManager(EntityManager *entityManager) : entityManager(entityManager) {}
  virtual ~SystemManager() {
      container.clear();
  }

  template<class TSystem>
  TSystem *Get() {
      return container[TSystem::STATIC_TYPE_ID];
  };

  template<class TSystem, class... TParam>
  TSystem *CreateAndGet(TParam &&... params) {
      auto system = new TSystem(std::forward<TParam>(params)...);
      container[TSystem::STATIC_TYPE_ID] = system;
      system->OnCreated();
      return system;
  };

  template<class TSystem>
  void Destroy() {
      container.erase(TSystem::STATIC_TYPE_ID);
  }
};
}

#endif //ROGUELIKE_SYSTEMMANAGER_H
