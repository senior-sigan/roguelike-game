/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#include <game/systems/MovementSystem.h>

void MovementSystem::ProcessEntity(ECS::IEntity *entity, double dt) {
    // TODO: apply movement only when it's allowed.
    // Movement could be blocked because of collision in the future.
    // Collision system checks collisions right now and here,
    // but we need to check collisions in the future when movement force will be applied.
    auto tc = entity->GetComponent<TransformComponent>();
    auto mc = entity->GetComponent<MovementComponent>();

    tc->position.x += mc->force.x*mc->direction.x;
    tc->position.y += mc->force.y*mc->direction.y;

    if (mc->force.x!=0) {
        mc->force.x -= mc->slowDownSpeed.x;
    }
    if (mc->force.y!=0) {
        mc->force.y -= mc->slowDownSpeed.y;
    }

    if (mc->force.x < 0) mc->force.x = 0;
    if (mc->force.y < 0) mc->force.y = 0;
}
const bool MovementSystem::FamilyFilter(ECS::IEntity const *entity) const {
    return entity->HasComponent<MovementComponent>() &&
        entity->HasComponent<TransformComponent>();
}
