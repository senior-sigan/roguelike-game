/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#include <game/systems/CollisionSystem.h>

using namespace Core;

std::pair<Vector2, Vector2> CollisionSystem::coordinates(const ECS::IEntity *entity) {
    auto bcc = entity->GetComponent<BoxColliderComponent>();
    auto tc = entity->GetComponent<TransformComponent>();

    int xLeft = tc->position.x + bcc->offset.x;
    int yUpper = tc->position.y - bcc->offset.y;
    int xRight = xLeft + bcc->size.x - 1;
    int yBottom = yUpper + bcc->size.y - 1;

    return std::make_pair(Vector2(xLeft, yUpper), Vector2(xRight, yBottom));
}
bool CollisionSystem::isIntersect(std::pair<Vector2, Vector2> r1, std::pair<Vector2, Vector2> r2) {
    return !(r2.first.x > r1.second.x
        || r2.second.x < r1.first.x
        || r2.first.y > r1.second.y
        || r2.second.y < r1.first.y);
}
void CollisionSystem::PreProcessEntity(ECS::IEntity *entity, double dt) {
    // Before each collision system iteration
    // we clear registered collisions on the previous step.
    entity->GetComponent<BoxColliderComponent>()->Clear();
}
void CollisionSystem::ProcessEntity(ECS::IEntity *entity, double dt) {
    auto bc1 = entity->GetComponent<BoxColliderComponent>();
    auto box1 = coordinates(entity);

    for (auto other: GetEntityManager()->container) {
        auto entity2 = other.second;
        if (entity2==entity) continue;
        auto bc2 = entity2->GetComponent<BoxColliderComponent>();
        auto box2 = coordinates(entity2);
        if (isIntersect(box1, box2)) {
            bc1->Collide(entity2);
            bc2->Collide(entity);
        }
    }
}
const bool CollisionSystem::FamilyFilter(ECS::IEntity *entity) const {
    // TODO: actually it should be a collider of any type, but our components storage cannot do look up with parents, only by ids.
    return entity->HasComponent<BoxColliderComponent>() && entity->HasComponent<TransformComponent>();
}
