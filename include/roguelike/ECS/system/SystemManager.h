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

  std::map<SystemTypeID, ISystemPtr> container;  // special storage for fast lookup

  EntityManagerPtr entityManager;
  Event::EventDispatcher *eventDispatcher;
  IEngineControl *engineControl;

  void Update(double delta);

 public:
  explicit SystemManager(const EntityManagerPtr &entityManager, Event::EventDispatcher *eventDispatcher,
                         IEngineControl *engineControl1);
  virtual ~SystemManager();

  template<class TSystem>
  std::shared_ptr<TSystem> Get() {
    return std::static_pointer_cast<TSystem>(container[TSystem::STATIC_TYPE_ID]);
  }

  template<class TSystem, class... TParam>
  void Create(TParam &&... params) {
    auto system = new TSystem(std::forward<TParam>(params)...);
    system->eventSender = eventDispatcher->eventSender;
    system->eventListener = eventDispatcher->eventListener;
    system->engineControl = engineControl;
    system->entityManager = entityManager;
    system->OnCreated();
    container[TSystem::STATIC_TYPE_ID] = std::shared_ptr<TSystem>(system);
    LOG_INFO("System was created: " << typeid(TSystem).name());
  }

  template<class TSystem>
  void Destroy() {
    auto system = container[TSystem::STATIC_TYPE_ID];
    system->OnDestroy();
    container.erase(TSystem::STATIC_TYPE_ID);
  }

  void DestroyAllSystems() {
    for (auto system : container) {
      system.second->OnDestroy();
    }
    container.clear();
  }
};

typedef std::shared_ptr<SystemManager> SystemManagerPtr;
}

#endif  // ROGUELIKE_SYSTEMMANAGER_H
