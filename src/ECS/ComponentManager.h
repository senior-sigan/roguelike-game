/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_COMPONENTMANAGER_H
#define ROGUELIKE_COMPONENTMANAGER_H

#include "Platform.h"
namespace ECS {
class ComponentManager {
 public:
  template<class C, class ...P>
  C *AddComponent(const EntityID entityID, P &&... params) const {
      // TODO
      return nullptr;
  }
  template<class C>
  C *GetComponent() const {
      // TODO
      return nullptr;
  }
  template<class C>
  void RemoveComponent() const {
      // TODO
  }
};
}

#endif //ROGUELIKE_COMPONENTMANAGER_H
