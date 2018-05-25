/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_COMPONENTMANAGER_H
#define ROGUELIKE_COMPONENTMANAGER_H

#include "IEntity.h"
namespace ECS {
class IComponentManager {
 public:
  template<class C, class ...P>
  virtual C *AddComponent(EntityID, P &&... params) const = 0;
  template<class C>
  virtual C *GetComponent() const = 0;
  template<class C>
  virtual void RemoveComponent() const = 0;
};
}

#endif //ROGUELIKE_COMPONENTMANAGER_H
