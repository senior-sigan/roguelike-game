
#include <iostream>
#include "ECS/Entity.h"
#include "ECS/EntityManager.h"
#include "ECS/Component.h"
#include "ECS/Engine.h"

class TransformComponent : public ECS::Component<TransformComponent> {
 public:
  int x = 0;
  int y = 0;
};

class GameObject : public ECS::Entity<GameObject> {
 public:
  void OnCreated() override {
      AddComponent<TransformComponent>();
  }
};

class AnotherObject : public ECS::Entity<AnotherObject> {

};

int main() {
    auto engine = new ECS::Engine();
    auto em = engine->GetEntityManager();
    auto e1 = em->CreateAndGet<GameObject>();
    auto e2 = em->CreateAndGet<AnotherObject>();
    auto e3 = em->CreateAndGet<GameObject>();
    std::cout << "GameObject 1= " << e1->GetID() << " " << e1->GetTypeID() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.ownerID= "
              << e1->GetComponent<TransformComponent>()->GetEntity() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.id= "
              << e1->GetComponent<TransformComponent>()->GetID() << std::endl;
    std::cout << "GameObject 1 # TransformComponent.typeID= "
              << e1->GetComponent<TransformComponent>()->GetTypeID() << std::endl;

    std::cout << "AnotherObject 1= " << e2->GetID() << " " << e2->GetTypeID() << std::endl;

    std::cout << "GameObject 2= " << e3->GetID() << " " << e3->GetTypeID() << std::endl;
    std::cout << "GameObject 2 # TransformComponent.ownerID= "
              << e3->GetComponent<TransformComponent>()->GetEntity() << std::endl;
    std::cout << "GameObject 2 # TransformComponent.id= "
              << e3->GetComponent<TransformComponent>()->GetID() << std::endl;
    std::cout << "GameObject 2 # TransformComponent.typeID= "
              << e3->GetComponent<TransformComponent>()->GetTypeID() << std::endl;
    return 0;
}