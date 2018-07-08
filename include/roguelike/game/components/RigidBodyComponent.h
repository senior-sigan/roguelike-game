/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_RIGIDBODYCOMPONENT_H
#define ROGUELIKE_RIGIDBODYCOMPONENT_H

#include <ECS/IComponent.h>

/**
 * Physical body. Add kinematics and so on. Has mass.
 * Can set constrains on movements.
 */
class RigidBodyComponent : public ECS::IComponent {};

#endif  // ROGUELIKE_RIGIDBODYCOMPONENT_H
