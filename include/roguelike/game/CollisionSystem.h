/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_COLLISIONSYSTEM_H
#define ROGUELIKE_COLLISIONSYSTEM_H

#include <ECS/system/IteratingSystem.h>

/**
 * Respond to calculate collisions of the all ColliderComponents
 */
class CollisionSystem: public ECS::IteratingSystem<CollisionSystem> {
    // TODO: iterate over all BoxColliderComponents and check collisions, notify
};

#endif //ROGUELIKE_COLLISIONSYSTEM_H
