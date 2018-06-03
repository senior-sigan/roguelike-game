#include <utility>

#include <iostream>
#include "../../src/ECS/Entity.h"
#include "../../src/ECS/EntityManager.h"
#include "../../src/ECS/Component.h"
#include "../../src/ECS/Engine.h"
#include "../../src/ECS/System.h"
#include "../../src/ECS/Event/Event.h"
#include <thread>

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

class RepeatedEvent : public ECS::Event::Event<RepeatedEvent> {};

class MovementSystem : public ECS::System<MovementSystem> {
 public:
  void OnCreated() override {}
  void Update(ECS::IEntity *entity, double dt) override {
      auto component = entity->GetComponent<TransformComponent>();
      component->x += 1;
      component->y += 1;
      std::stringstream ss;
      ss << entity->GetTypeID() << " MovementSystem: " << component->x << " " << component->y;
      eventSender->Send<MovementEvent>(ss.str());
  }

  const bool FamilyFilter(ECS::IEntity *entity) const override {
      return entity->HasComponent<TransformComponent>();
  }
};

class ListenerSystem : public ECS::System<ListenerSystem> {
  LOG_INIT("ListenerSystem");
 public:
  void OnCreated() override {
      eventListener->RegisterListener<ListenerSystem, MovementEvent>(this, &ListenerSystem::OnMovementEvent);
      eventListener->RegisterListener<ListenerSystem, RepeatedEvent>(this, &ListenerSystem::OnRepeatedEvent);

      eventSender->SendInterval<RepeatedEvent>(0, 0, 3);
  }

  void OnMovementEvent(const MovementEvent const *event) {
      LOG_INFO("MovementEvent(" << event->GetTypeId() << "): " << event->msg);
  }

  void OnRepeatedEvent(const RepeatedEvent const *event) {
      LOG_INFO("RepeatedEvent(" << event->GetTypeId() << "): ");
  }
};

class ExitSystem : public ECS::System<ExitSystem> {
  long rounds = 0;
  const long maxRounds = 10;
 public:
  void SysUpdate(double dt) override {
      // Just emulate some work;
      rounds += 1;
      if (rounds > maxRounds) engineControl->Stop();
      std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
};

int ECS_test_main() {
    LOG_CONFIGURE();
    LOG_INIT("ECS_test_main");
    auto engine = new ECS::Engine();
    auto em = engine->GetEntityManager();
    auto sm = engine->GetSystemManager();

    sm->CreateAndGet<MovementSystem>();
    sm->CreateAndGet<ListenerSystem>();
    sm->CreateAndGet<ExitSystem>();
    auto e1 = em->CreateAndGet<GameObject>();
    auto e2 = em->CreateAndGet<AnotherObject>();

    LOG_INFO("GameObject 1= " << e1->GetID() << " " << e1->GetTypeID());
    LOG_INFO("GameObject 1 # TransformComponent.ownerID= "
                 << e1->GetComponent<TransformComponent>()->GetEntity());
    LOG_INFO("GameObject 1 # TransformComponent.id= "
                 << e1->GetComponent<TransformComponent>()->GetID());
    LOG_INFO("GameObject 1 # TransformComponent.typeID= "
                 << e1->GetComponent<TransformComponent>()->GetTypeID());

    LOG_INFO("AnotherObject 1= " << e2->GetID() << " " << e2->GetTypeID());

    LOG_INFO("GameLoop");
    engine->Loop();
}