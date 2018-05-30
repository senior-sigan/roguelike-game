/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_SYSTEMMANAGER_H
#define ROGUELIKE_SYSTEMMANAGER_H

#include <map>
#include "Platform.h"
#include "ISystem.h"
#include "Event/EventDispatcher.h"
namespace ECS {
class SystemManager {
  friend class Engine;

  std::map<SystemTypeID, ISystem *> container;
  EntityManager *entityManager{};
  Event::EventDispatcher *eventDispatcher{};

  void Update(float delta) {
      // TODO: iterate over systems with some order which is set by priority property.

      for (auto entity : entityManager->container) {
          for (std::pair<SystemTypeID, ISystem *> system: container) {
              if (system.second->FamilyFilter(entity.second)) {
                  system.second->PreUpdate(entity.second, delta);
              }
          }
      }

      for (auto entity : entityManager->container) {
          for (std::pair<SystemTypeID, ISystem *> system: container) {
              if (system.second->FamilyFilter(entity.second)) {
                  system.second->Update(entity.second, delta);
              }
          }
      }

      for (auto entity : entityManager->container) {
          for (std::pair<SystemTypeID, ISystem *> system: container) {
              if (system.second->FamilyFilter(entity.second)) {
                  system.second->PostUpdate(entity.second, delta);
              }
          }
      }
  };

 public:
  explicit SystemManager(EntityManager *entityManager, Event::EventDispatcher *eventDispatcher) :
      entityManager(entityManager), eventDispatcher(eventDispatcher) {}
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
      system->eventDispatcher = eventDispatcher;
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
