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

  void Update(double deltaTime) override;
 public:
  Engine();

  virtual ~Engine();

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

  void Stop() override;
};
}
#endif //ROGUELIKE_ENGINE_H
