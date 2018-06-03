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
  LOG_INIT("SystemManager");
  friend class Engine;

  std::map<SystemTypeID, ISystem *> container;
  EntityManager *entityManager{};
  Event::EventDispatcher *eventDispatcher;
  IEngineControl *engineControl;

  void Update(double delta);;

 public:
  explicit SystemManager(EntityManager *entityManager,
                         Event::EventDispatcher *eventDispatcher,
                         IEngineControl *engineControl1);
  virtual ~SystemManager();

  template<class TSystem>
  TSystem *Get() {
      return container[TSystem::STATIC_TYPE_ID];
  };

  template<class TSystem, class... TParam>
  TSystem *CreateAndGet(TParam &&... params) {
      auto system = new TSystem(std::forward<TParam>(params)...);
      system->eventSender = eventDispatcher->eventSender;
      system->eventListener = eventDispatcher->eventListener;
      system->engineControl = engineControl;
      container[TSystem::STATIC_TYPE_ID] = system;
      system->OnCreated();
      LOG_INFO("System was created: " << typeid(TSystem).name());
      return system;
  };

  template<class TSystem>
  void Destroy() {
      container.erase(TSystem::STATIC_TYPE_ID);
  }
};
}

#endif //ROGUELIKE_SYSTEMMANAGER_H
