/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ICOMPONENT_H
#define ROGUELIKE_ICOMPONENT_H

#include "Platform.h"
namespace ECS {

class IComponent {
  friend class ComponentManager;

  ComponentID componentID{};
  EntityID ownerID{};

 public:
  virtual const ComponentTypeID GetTypeID() const = 0;

  const ComponentID GetID() const {
      return this->componentID;
  };

  const EntityID GetEntity() const {
      return this->ownerID;
  };

  virtual void OnCreated() {};
};
}

#endif //ROGUELIKE_ICOMPONENT_H
