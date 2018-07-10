/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/components/MovementComponent.h>
#include <game/systems/ControlSystem.h>

void ControlSystem::ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) {
  auto cc = entity->GetComponent<ControlComponent>();
  auto mc = entity->GetComponent<MovementComponent>();

  if (Input::Instance().GetButtonDown(cc->up)) {
    mc->force.y += mc->speed.y;
    mc->direction = Core::Vector2::UP;
  }
  if (Input::Instance().GetButtonDown(cc->down)) {
    mc->force.y += mc->speed.y;
    mc->direction = Core::Vector2::DOWN;
  }
  if (Input::Instance().GetButtonDown(cc->right)) {
    mc->force.x += mc->speed.x;
    mc->direction = Core::Vector2::RIGHT;
  }
  if (Input::Instance().GetButtonDown(cc->left)) {
    mc->force.x += mc->speed.x;
    mc->direction = Core::Vector2::LEFT;
  }
}

bool ControlSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<ControlComponent>() && entity->HasComponent<MovementComponent>();
}
