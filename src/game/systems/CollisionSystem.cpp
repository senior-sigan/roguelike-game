/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#include <core/Geometry.h>
#include <game/systems/CollisionSystem.h>

namespace {

Core::Rectangle rectangle(const ECS::IEntityPtr &entity) {
  auto bcc = entity->GetComponent<BoxColliderComponent>();
  auto tc = entity->GetComponent<TransformComponent>();

  auto xLeft = tc->position.x + bcc->offset.x;
  auto yUpper = tc->position.y - bcc->offset.y;

  return Core::Rectangle(Core::Vector2(xLeft, yUpper), bcc->size);
}

}

void CollisionSystem::PreProcessEntity(const ECS::IEntityPtr &entity, f64 dt) {
  // Before each collision system iteration
  // we clear registered collisions on the previous step.
  entity->GetComponent<BoxColliderComponent>()->Clear();
}
void CollisionSystem::ProcessEntity(const ECS::IEntityPtr &entity, f64 dt) {
  auto bc1 = entity->GetComponent<BoxColliderComponent>();
  if (!bc1->isMovable) {
    // We do not need to check whether non-movable objects collide or not.
    return;
  }
  auto box1 = rectangle(entity);

  for (auto other : GetEntityManager()->container) {
    auto entity2 = other.second;
    if (entity2 == entity) continue;
    auto bc2 = entity2->GetComponent<BoxColliderComponent>();
    auto box2 = rectangle(entity2);
    if (Intersect(box1, box2)) {
      bc1->Collide(entity2);
      bc2->Collide(entity);
    }
  }
}
bool CollisionSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  // TODO: actually it should be a collider of any type, but our components storage cannot do look up with parents, only
  // by ids.
  return entity->HasComponent<BoxColliderComponent>() && entity->HasComponent<TransformComponent>();
}
