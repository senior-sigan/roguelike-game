/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/systems/ControlSystem.h>

void ControlSystem::ProcessEntityInterval(ECS::IEntity *entity, double dt) {
    auto tc = entity->GetComponent<TransformComponent>();
    auto cc = entity->GetComponent<ControlComponent>();

    // TODO: it should be in a component
    int horizontalSpeed = 1;
    int verticalSpeed = 1;

    if (inputSystem->GetButtonDown(cc->up)) {
        tc->position.y -= horizontalSpeed;
    }
    if (inputSystem->GetButtonDown(cc->down)) {
        tc->position.y += horizontalSpeed;
    }
    if (inputSystem->GetButtonDown(cc->right)) {
        tc->position.x += horizontalSpeed;
    }
    if (inputSystem->GetButtonDown(cc->left)) {
        tc->position.x -= horizontalSpeed;
    }
}

const bool ControlSystem::FamilyFilter(ECS::IEntity *entity) const {
    return entity->HasComponent<ControlComponent>() && entity->HasComponent<TransformComponent>();
}

void ControlSystem::OnCreated() {
    inputSystem = GetEngineControl()->GetSystemManager()->Get<InputSystem>();
}
