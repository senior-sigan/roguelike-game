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
  entityManager->SweepDeleted();
  // TODO: destroy entities, components, resend destruction events.
}
Engine::Engine() {
  eventListener = std::make_shared<Event::EventListener>();
  eventSender = std::make_shared<Event::EventSender>();
  eventDispatcher = std::make_shared<Event::EventDispatcher>(eventSender, eventListener);
  componentManager = std::make_shared<ComponentManager>();
  entityManager = std::make_shared<EntityManager>(componentManager);
  systemManager = std::make_shared<SystemManager>(entityManager, eventDispatcher, this);
}
void Engine::Stop() {
  GameLoop::Stop();
}
void Engine::OnDestroy() {
  systemManager->DestroyAllSystems();
  entityManager->DestroyAllEntities();
  componentManager->DestroyAllComponents();
}
}