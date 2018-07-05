/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ENGINE_H
#define ROGUELIKE_ENGINE_H

#include "ECS/ComponentManager.h"
#include "ECS/EntityManager.h"
#include "ECS/Event/EventDispatcher.h"
#include "ECS/GameLoop.h"
#include "ECS/IEngineControl.h"
#include "ECS/system/SystemManager.h"
namespace ECS {
class Engine : public IEngineControl, public GameLoop {
  LOG_INIT("Engine");
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

  void OnDestroy();
};
}
#endif  // ROGUELIKE_ENGINE_H
