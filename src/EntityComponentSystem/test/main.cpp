#include <utility>

#include <iostream>
#include "ECS/Entity.h"
#include "ECS/EntityManager.h"
#include "ECS/Component.h"
#include "ECS/Engine.h"
#include "ECS/System.h"
#include "ECS/Event/Event.h"
#include <thread>
#include <sstream>

class TransformComponent : public ECS::Component<TransformComponent> {
 public:
  TransformComponent(int x, int y) : x(x), y(y) {}
  int x;
  int y;
};

class GameObject : public ECS::Entity<GameObject> {
 public:
  void OnCreated() override {
      AddComponent<TransformComponent>(0, 0);
  }
};

class AnotherObject : public ECS::Entity<AnotherObject> {
 public:
  void OnCreated() override {
      AddComponent<TransformComponent>(10, 10);
  }
};

class MovementEvent : public ECS::Event::Event<MovementEvent> {
 public:
  const std::string msg;
  explicit MovementEvent(std::string msg) : msg(std::move(msg)) {}
};

class MovementSystem : public ECS::System<MovementSystem> {
 public:
  void OnCreated() override {}
  void Update(ECS::IEntity *entity, float dt) override {
      auto component = entity->GetComponent<TransformComponent>();
      component->x += 1;
      component->y += 1;
      std::stringstream ss;
      ss << entity->GetTypeID() << " MovementSystem: " << component->x << " " << component->y << std::endl;
      eventSender->Send<MovementEvent>(ss.str());
  }

  const bool FamilyFilter(ECS::IEntity *entity) const override {
      return entity->HasComponent<TransformComponent>();
  }
};

class ListenerSystem : public ECS::System<ListenerSystem> {
 public:
  void OnCreated() override {
      eventListener->RegisterListener<ListenerSystem, MovementEvent>(this, &ListenerSystem::OnMovementEvent);
  }

  void OnMovementEvent(const MovementEvent const *event) {
      std::cout << event->msg << std::endl;
  }
};

int main() {
    auto engine = new ECS::Engine();
    auto em = engine->GetEntityManager();
    auto sm = engine->GetSystemManager();

    sm->CreateAndGet<MovementSystem>();
    sm->CreateAndGet<ListenerSystem>();
    auto e1 = em->CreateAndGet<GameObject>();
    auto e2 = em->CreateAndGet<AnotherObject>();

    std::cout << "GameObject 1= " << e1->GetID() << " " << e1->GetTypeID() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.ownerID= "
              << e1->GetComponent<TransformComponent>()->GetEntity() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.id= "
              << e1->GetComponent<TransformComponent>()->GetID() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.typeID= "
              << e1->GetComponent<TransformComponent>()->GetTypeID() << std::endl;

    std::cout << "AnotherObject 1= " << e2->GetID() << " " << e2->GetTypeID() << std::endl;

    std::cout << "GameLoop" << std::endl;
    int i = 0;
    while (i < 10) {
        engine->Update();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        i++;
    }
}