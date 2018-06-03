/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_COMPONENTMANAGER_H
#define ROGUELIKE_COMPONENTMANAGER_H

#include "ECS.h"
#include <iostream>
#include <unordered_map>
#include "Platform.h"
#include "IComponent.h"

namespace ECS {
/**
 * C++ default hash function doesn't support pair. This is our implementation.
 * https://stackoverflow.com/questions/20590656/error-for-hash-function-of-pair-of-ints?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
 */
struct pairhash {
  template<typename T, typename U>
  size_t operator()(const std::pair<T, U> &p) const {
      size_t h1 = std::hash<T>()(p.first);
      size_t h2 = std::hash<U>()(p.second);
      return h1 ^ (h2 << 1);
  }
};

class ComponentManager {
  std::unordered_map<std::pair<EntityID, ComponentTypeID>, IComponent *, pairhash> container;
  ComponentID currentID = 0;
 public:
  ComponentManager() {
      LOG_INFO("Initialize ComponentManager");
  }

  template<class TComponent, class ...TParam>
  TComponent *AddComponent(const EntityID entityID, TParam &&... params) {
      auto component = new TComponent(std::forward<TParam>(params)...);
      auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
      component->ownerID = entityID;
      component->componentID = currentID++;
      container[key] = component;
      component->OnCreated();
      return component;
  }
  template<class TComponent>
  TComponent *GetComponent(EntityID entityID) {
      auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
      return (TComponent *) container[key];
  }
  template<class TComponent>
  void RemoveComponent(EntityID entityID) {
      auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
      container.erase(key);
  }
};
}

#endif //ROGUELIKE_COMPONENTMANAGER_H
