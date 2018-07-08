/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ICOMPONENT_H
#define ROGUELIKE_ICOMPONENT_H

#include "ECS/Platform.h"
namespace ECS {

class IComponent {
  friend class ComponentManager;

  ComponentID componentID{};
  EntityID ownerID{};

 public:
  ComponentID GetID() const {
    return this->componentID;
  }

  EntityID GetEntity() const {
    return this->ownerID;
  }

  virtual void OnCreated() {}
};
}

#endif  // ROGUELIKE_ICOMPONENT_H
