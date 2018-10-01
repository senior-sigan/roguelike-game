/**
 * Created by Илья Сиганов on 26.05.2018.
 */

#ifndef ROGUELIKE_IENTITY_H
#define ROGUELIKE_IENTITY_H

#include <ECS/ComponentManager.h>
#include <ECS/Platform.h>
namespace ECS {
class IEntity {
  friend class EntityManager;

  ComponentManagerPtr componentManager;  // TODO: should be filled in the EntityManager
  EntityID entityID{};                   // TODO: should bew filled in the EntityManager

 public:
  virtual ~IEntity() = default;

  EntityID GetID() const { return entityID; }

  template<class TComponent>
  std::shared_ptr<TComponent> GetComponent() const {
    return componentManager->GetComponent<TComponent>(entityID);
  }

  template<class TComponent>
  bool HasComponent() const {
    auto component = componentManager->GetComponent<TComponent>(entityID);
    return component != nullptr;
  }

  template<class TComponent, class... TParam>
  void AddComponent(TParam &&... params) {
    componentManager->AddComponent<TComponent>(entityID, std::forward<TParam>(params)...);
  }

  template<class TComponent>
  void RemoveComponent() {
    componentManager->RemoveComponent<TComponent>(entityID);
  }

  void RemoveAllComponents() {
    componentManager->RemoveAllComponents(entityID);
  }

  virtual void OnCreated() {}

  bool operator==(const IEntity &rhs) const {
    return entityID == rhs.entityID;
  }
  bool operator!=(const IEntity &rhs) const {
    return entityID != rhs.entityID;
  }
};

typedef std::shared_ptr<IEntity> IEntityPtr;
}

#endif  // ROGUELIKE_IENTITY_H
