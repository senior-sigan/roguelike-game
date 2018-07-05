/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/components/MovementComponent.h>
#include <game/systems/ControlSystem.h>

void ControlSystem::ProcessEntityInterval(ECS::IEntity* entity, double dt) {
  auto cc = entity->GetComponent<ControlComponent>();
  auto mc = entity->GetComponent<MovementComponent>();

  if (inputSystem->GetButtonDown(cc->up)) {
    mc->force.y += mc->speed.y;
    mc->direction = Core::Vector2::UP;
  }
  if (inputSystem->GetButtonDown(cc->down)) {
    mc->force.y += mc->speed.y;
    mc->direction = Core::Vector2::DOWN;
  }
  if (inputSystem->GetButtonDown(cc->right)) {
    mc->force.x += mc->speed.x;
    mc->direction = Core::Vector2::RIGHT;
  }
  if (inputSystem->GetButtonDown(cc->left)) {
    mc->force.x += mc->speed.x;
    mc->direction = Core::Vector2::LEFT;
  }
}

bool ControlSystem::FamilyFilter(ECS::IEntity* entity) const {
  return entity->HasComponent<ControlComponent>() && entity->HasComponent<MovementComponent>();
}

void ControlSystem::OnCreated() {
  inputSystem = GetEngineControl()->GetSystemManager()->Get<InputSystem>();
}