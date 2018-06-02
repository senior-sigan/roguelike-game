/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ENGINE_H
#define ROGUELIKE_ENGINE_H

#include "EntityManager.h"
#include "SystemManager.h"
#include "ComponentManager.h"
#include "Event/EventDispatcher.h"
namespace ECS {
class Engine {
  EntityManager *entityManager;
  ComponentManager *componentManager;
  SystemManager *systemManager;
  Event::EventDispatcher *eventDispatcher;
  Event::EventListener *eventListener;
  Event::EventSender *eventSender;
 public:
  Engine() {
      eventListener = new Event::EventListener();
      eventSender = new Event::EventSender();
      eventDispatcher = new Event::EventDispatcher(eventSender, eventListener);
      componentManager = new ComponentManager();
      entityManager = new EntityManager(componentManager);
      systemManager = new SystemManager(entityManager, eventDispatcher);
  }

  virtual ~Engine() {
      delete systemManager;
      systemManager = nullptr;

      delete entityManager;
      entityManager = nullptr;

      delete componentManager;
      componentManager = nullptr;

      delete eventDispatcher;
      eventDispatcher = nullptr;
  }

  void Update() {
      auto deltaTime = 0;
      // TODO: calculate game delta time
      // TODO: may be instead of delta time we'll have step number? So ticker class should be abstract so we can support delta time and delta step.
      systemManager->Update(deltaTime);
      eventDispatcher->DispatchEvents(deltaTime);
      // TODO: May be registerCall manual entities destruction and resend events again.
  }

  EntityManager *GetEntityManager() const {
      return entityManager;
  }
  ComponentManager *GetComponentManager() const {
      return componentManager;
  }
  SystemManager *GetSystemManager() const {
      return systemManager;
  }
  Event::EventDispatcher *GetEventHandler() const {
      return eventDispatcher;
  }
};
}
#endif //ROGUELIKE_ENGINE_H
