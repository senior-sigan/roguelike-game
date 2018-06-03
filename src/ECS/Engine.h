/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ENGINE_H
#define ROGUELIKE_ENGINE_H

#include "EntityManager.h"
#include "SystemManager.h"
#include "ComponentManager.h"
#include "Event/EventDispatcher.h"
#include "GameLoop.h"
#include "IEngineControl.h"
namespace ECS {
class Engine : public IEngineControl, public GameLoop {
  EntityManager *entityManager;
  ComponentManager *componentManager;
  SystemManager *systemManager;
  Event::EventDispatcher *eventDispatcher;
  Event::EventListener *eventListener;
  Event::EventSender *eventSender;

  void Update(double deltaTime) override {
      // TODO: may be instead of delta time we'll have step number? So ticker class should be abstract so we can support delta time and delta step.
      systemManager->Update(deltaTime);
      eventDispatcher->DispatchEvents(deltaTime);
      // TODO: destroy entities, components, resend destruction events.
  }
 public:
  Engine() {
      eventListener = new Event::EventListener();
      eventSender = new Event::EventSender();
      eventDispatcher = new Event::EventDispatcher(eventSender, eventListener);
      componentManager = new ComponentManager();
      entityManager = new EntityManager(componentManager);
      systemManager = new SystemManager(entityManager, eventDispatcher, this);
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

  EntityManager *GetEntityManager() const override {
      return entityManager;
  }
  ComponentManager *GetComponentManager() const override {
      return componentManager;
  }
  SystemManager *GetSystemManager() const override {
      return systemManager;
  }
  Event::EventDispatcher *GetEventHandler() const override {
      return eventDispatcher;
  }

  void Stop() override {
      ((GameLoop *) this)->Stop();
  }
};
}
#endif //ROGUELIKE_ENGINE_H
