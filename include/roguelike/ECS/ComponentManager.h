/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_COMPONENTMANAGER_H
#define ROGUELIKE_COMPONENTMANAGER_H

#include <ECS/IComponent.h>
#include <ECS/Platform.h>
#include <Log/logging.h>
#include <unordered_map>
#include <utility>

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
  LOG_INIT("ComponentManager");
  std::unordered_map<std::pair<EntityID, ComponentTypeID>, std::shared_ptr<IComponent>, pairhash> container;
  ComponentID currentID = 0;

 public:
  ComponentManager() {
    LOG_INFO("ComponentManager was initialized");
  }

  template<class TComponent, class... TParam>
  void AddComponent(const EntityID entityID, TParam &&... params) {
    auto component = new TComponent(std::forward<TParam>(params)...);
    auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
    component->ownerID = entityID;
    component->componentID = currentID++;
    container[key] = std::shared_ptr<TComponent>(component);
    component->OnCreated();
  }
  template<class TComponent>
  std::shared_ptr<TComponent> GetComponent(EntityID entityID) {
    auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
    return std::static_pointer_cast<TComponent>(container[key]);
  }
  template<class TComponent>
  void RemoveComponent(EntityID entityID) {
    auto key = std::make_pair(entityID, TComponent::STATIC_TYPE_ID);
    container.erase(key);
  }

  void RemoveAllComponents(EntityID entityID) {
    // TODO: get from the container all components and remove them
  }

  void DestroyAllComponents() {
    container.clear();
  }
};

typedef std::shared_ptr<ComponentManager> ComponentManagerPtr;
}

#endif  // ROGUELIKE_COMPONENTMANAGER_H
