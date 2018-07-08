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
  EntityManagerPtr entityManager;
  ComponentManagerPtr componentManager;
  SystemManagerPtr systemManager;
  Event::EventDispatcherPtr eventDispatcher;
  Event::EventListenerPtr eventListener;
  Event::EventSenderPtr eventSender;

  void Update(double deltaTime) override;

 public:
  Engine();

  EntityManagerPtr GetEntityManager() const override {
    return entityManager;
  }
  ComponentManagerPtr GetComponentManager() const override {
    return componentManager;
  }
  SystemManagerPtr GetSystemManager() const override {
    return systemManager;
  }
  Event::EventDispatcherPtr GetEventHandler() const override {
    return eventDispatcher;
  }

  void Stop() override;

  void OnDestroy();
};

typedef std::shared_ptr<Engine> EnginePtr;
}
#endif  // ROGUELIKE_ENGINE_H
