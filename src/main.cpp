
#include <iostream>
#include "ECS/Entity.h"

class GameObject : public ECS::Entity<GameObject> {

};

class AnotherObject : public ECS::Entity<AnotherObject> {

};

int main() {
    auto e1 = GameObject();
    auto e2 = AnotherObject();
    auto e3 = GameObject();
    std::cout << e1.GetID() << " " << e1.GetTypeID() << std::endl;
    std::cout << e2.GetID() << " " << e2.GetTypeID() << std::endl;
    std::cout << e3.GetID() << " " << e3.GetTypeID() << std::endl;
    return 0;
}