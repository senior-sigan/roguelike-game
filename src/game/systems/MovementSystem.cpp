/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#include <core/Geometry.h>
#include <core/Rectangle.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/MovementSystem.h>

namespace {
Core::Rectangle futureRectangle(const ECS::IEntityPtr &entity) {
  auto bcc = entity->GetComponent<BoxColliderComponent>();
  auto tc = entity->GetComponent<TransformComponent>();
  auto mc = entity->GetComponent<MovementComponent>();

  int xLeftFuture = tc->position.x + bcc->offset.x + mc->force.x * mc->direction.x;
  int yUpperFuture = tc->position.y - bcc->offset.y + mc->force.y * mc->direction.y;

  return Core::Rectangle(Core::Vector2(xLeftFuture, yUpperFuture), bcc->size);
}

Core::Rectangle rectangle(const ECS::IEntityPtr &entity) {
  auto bcc = entity->GetComponent<BoxColliderComponent>();
  auto tc = entity->GetComponent<TransformComponent>();

  int xLeft = tc->position.x + bcc->offset.x;
  int yUpper = tc->position.y - bcc->offset.y;

  return Core::Rectangle(Core::Vector2(xLeft, yUpper), bcc->size);
}

void applyForce(const TransformComponentPtr& tc, const MovementComponentPtr& mc) {
  tc->position.x += mc->force.x * mc->direction.x;
  tc->position.y += mc->force.y * mc->direction.y;

  if (mc->force.x != 0) {
    mc->force.x -= mc->slowDownSpeed.x;
  }
  if (mc->force.y != 0) {
    mc->force.y -= mc->slowDownSpeed.y;
  }

  if (mc->force.x < 0) mc->force.x = 0;
  if (mc->force.y < 0) mc->force.y = 0;
}

void stopMovement(const MovementComponentPtr &mc) {
  mc->force = Core::Vector2::ZERO;
}

/**
 * Checks collision
 *
 * @return true if no collisions otherwise false
 */
bool canApplyForce(const ECS::IEntityPtr &entity, const ECS::ISystem* const system) {
  if (!entity->HasComponent<BoxColliderComponent>()) return true;

  auto box1 = futureRectangle(entity);

  for (auto other : system->GetEntityManager()->container) {
    auto entity2 = other.second;
    if (entity2 == entity) continue;
    if (entity2->GetComponent<BoxColliderComponent>()->isTrigger) continue;
    auto box2 = rectangle(entity2);
    if (Intersect(box1, box2)) {
      return false;
    }
  }

  return true;
}
}

void MovementSystem::ProcessEntity(const ECS::IEntityPtr &entity, double dt) {
  // TODO: apply movement only when it's allowed.
  // Movement could be blocked because of collision in the future.
  // Collision system checks collisions right now and here,
  // but we need to check collisions in the future when movement force will be applied.
  auto tc = entity->GetComponent<TransformComponent>();
  auto mc = entity->GetComponent<MovementComponent>();

  if (canApplyForce(entity, this)) {
    applyForce(tc, mc);
  } else {
    stopMovement(mc);
  }
}

bool MovementSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<MovementComponent>() && entity->HasComponent<TransformComponent>();
}
