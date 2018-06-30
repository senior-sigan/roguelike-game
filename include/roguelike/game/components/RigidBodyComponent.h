/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_RIGIDBODYCOMPONENT_H
#define ROGUELIKE_RIGIDBODYCOMPONENT_H

#include <ECS/Component.h>

/**
 * Physical body. Add kinematics and so on. Has mass.
 * Can set constrains on movements.
 */
class RigidBodyComponent: public ECS::Component<RigidBodyComponent> {

};

#endif //ROGUELIKE_RIGIDBODYCOMPONENT_H
