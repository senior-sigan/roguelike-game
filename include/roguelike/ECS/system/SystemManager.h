/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_SYSTEMMANAGER_H
#define ROGUELIKE_SYSTEMMANAGER_H

#include <ECS/Event/EventDispatcher.h>
#include <ECS/Platform.h>
#include <ECS/system/ISystem.h>
#include <map>
#include <set>
namespace ECS {
class SystemManager {
  LOG_INIT("SystemManager");
  friend class Engine;

  std::map<SystemTypeID, ISystem *> container;  // special storage for fast lookup
  std::set<ISystem *> containerList;            // special storage for fast update

  EntityManager *entityManager{};
  Event::EventDispatcher *eventDispatcher;
  IEngineControl *engineControl;

  void Update(double delta);

  void Store(SystemTypeID id, ISystem *system) {
    container[id] = system;
    containerList.emplace(system);
  }

 public:
  explicit SystemManager(EntityManager *entityManager, Event::EventDispatcher *eventDispatcher,
                         IEngineControl *engineControl1);
  virtual ~SystemManager();

  template<class TSystem>
  TSystem *Get() {
    return static_cast<TSystem *>(container[TSystem::STATIC_TYPE_ID]);
  }

  template<class TSystem, class... TParam>
  TSystem *CreateAndGet(TParam &&... params) {
    auto system = new TSystem(std::forward<TParam>(params)...);
    system->eventSender = eventDispatcher->eventSender;
    system->eventListener = eventDispatcher->eventListener;
    system->engineControl = engineControl;
    system->entityManager = entityManager;
    system->OnCreated();
    Store(TSystem::STATIC_TYPE_ID, system);
    LOG_INFO("System was created: " << typeid(TSystem).name());
    return system;
  }

  template<class TSystem>
  void Destroy() {
    auto system = container[TSystem::STATIC_TYPE_ID];
    system->OnDestroy();
    containerList.erase(container[TSystem::STATIC_TYPE_ID]);
    container.erase(TSystem::STATIC_TYPE_ID);
  }

  void DestroyAllSystems() {
    for (auto system : containerList) {
      system->OnDestroy();
    }
    containerList.clear();
    container.clear();
  }
};
}

#endif  // ROGUELIKE_SYSTEMMANAGER_H
