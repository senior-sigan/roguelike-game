/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#include <game/systems/CollisionSystem.h>
#include <core/Geometry.h>

using namespace Core;

namespace {

Rectangle rectangle(const ECS::IEntity *entity) {
    auto bcc = entity->GetComponent<BoxColliderComponent>();
    auto tc = entity->GetComponent<TransformComponent>();

    int xLeft = tc->position.x + bcc->offset.x;
    int yUpper = tc->position.y - bcc->offset.y;

    return Rectangle(Vector2(xLeft, yUpper), bcc->size);
}

}

void CollisionSystem::PreProcessEntity(ECS::IEntity *entity, double dt) {
    // Before each collision system iteration
    // we clear registered collisions on the previous step.
    entity->GetComponent<BoxColliderComponent>()->Clear();
}
void CollisionSystem::ProcessEntity(ECS::IEntity *entity, double dt) {
    auto bc1 = entity->GetComponent<BoxColliderComponent>();
    auto box1 = rectangle(entity);

    for (auto other: GetEntityManager()->container) {
        auto entity2 = other.second;
        if (entity2==entity) continue;
        auto bc2 = entity2->GetComponent<BoxColliderComponent>();
        auto box2 = rectangle(entity2);
        if (Intersect(box1, box2)) {
            bc1->Collide(entity2);
            bc2->Collide(entity);
        }
    }
}
const bool CollisionSystem::FamilyFilter(ECS::IEntity const *entity) const {
    // TODO: actually it should be a collider of any type, but our components storage cannot do look up with parents, only by ids.
    return entity->HasComponent<BoxColliderComponent>() && entity->HasComponent<TransformComponent>();
}
