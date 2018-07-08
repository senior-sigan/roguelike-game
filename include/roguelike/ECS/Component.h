/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_COMPONENT_H
#define ROGUELIKE_COMPONENT_H

#include <ECS/IComponent.h>
namespace ECS {

template<class TComponent>
class Component : public ECS::IComponent {
  friend class ComponentManager;
};
}
#endif  // ROGUELIKE_COMPONENT_H
