
#include <iostream>
#include "ECS/Entity.h"
#include "ECS/EntityManager.h"

class GameObject : public ECS::Entity<GameObject> {

};

class AnotherObject : public ECS::Entity<AnotherObject> {

};

int main() {
    auto em = ECS::EntityManager();
    auto e1 = em.CreateAndGet<GameObject>();
    auto e2 = em.CreateAndGet<AnotherObject>();
    auto e3 = em.CreateAndGet<GameObject>();
    std::cout << e1->GetID() << " " << e1->GetTypeID() << std::endl;
    std::cout << e2->GetID() << " " << e2->GetTypeID() << std::endl;
    std::cout << e3->GetID() << " " << e3->GetTypeID() << std::endl;
    return 0;
}