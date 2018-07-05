/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/Engine.h>

namespace ECS {
void Engine::Update(double deltaTime) {
  // TODO: may be instead of delta time we'll have step number?
  // So ticker class should be abstract so we can support delta time and delta step.
  systemManager->Update(deltaTime);
  eventDispatcher->DispatchEvents(deltaTime);
  // TODO: destroy entities, components, resend destruction events.
}
Engine::Engine() {
  eventListener = new Event::EventListener();
  eventSender = new Event::EventSender();
  eventDispatcher = new Event::EventDispatcher(eventSender, eventListener);
  componentManager = new ComponentManager();
  entityManager = new EntityManager(componentManager);
  systemManager = new SystemManager(entityManager, eventDispatcher, this);
  LOG_INFO("Engine was initialized");
}
Engine::~Engine() {
  delete systemManager;
  systemManager = nullptr;

  delete entityManager;
  entityManager = nullptr;

  delete componentManager;
  componentManager = nullptr;

  delete eventDispatcher;
  eventDispatcher = nullptr;
}
void Engine::Stop() {
  static_cast<GameLoop*>(this)->Stop();
}
void Engine::OnDestroy() {
  systemManager->DestroyAllSystems();
}
}