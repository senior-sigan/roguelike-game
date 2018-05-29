/**
 * Created by Илья Сиганов on 26.05.2018.
 */

#ifndef ROGUELIKE_IENTITY_H
#define ROGUELIKE_IENTITY_H

#include "Platform.h"
#include "ComponentManager.h"
namespace ECS {
class IEntity {
  friend class EntityManager;

  ComponentManager *componentManager{}; // TODO: should be filled in the EntityManager
  EntityID entityID{}; // TODO: should bew filled in the EntityManager
 public:
  virtual const EntityTypeID GetTypeID() const = 0;

  const EntityID GetID() const {
      return entityID;
  }

  template<class TComponent>
  TComponent *GetComponent() const {
      return this->componentManager->GetComponent<TComponent>(entityID);
  }

  template<class TComponent, class ...TParam>
  TComponent *AddComponent(TParam &&... params) {
      return this->componentManager->AddComponent<TComponent>(entityID, std::forward<TParam>(params)...);
  }

  template<class TComponent>
  void RemoveComponent() {
      this->componentManager->RemoveComponent<TComponent>(entityID);
  }

  virtual void OnCreated() {};
};
}

#endif //ROGUELIKE_IENTITY_H
