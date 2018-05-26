/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ICOMPONENT_H
#define ROGUELIKE_ICOMPONENT_H

#include "Platform.h"
namespace ECS {

class IComponent {
 public:
  virtual const ComponentTypeID GetTypeID() const = 0;

  virtual const ComponentID GetID() const = 0;

  virtual const EntityID GetEntity() const = 0;
};
}

#endif //ROGUELIKE_ICOMPONENT_H
