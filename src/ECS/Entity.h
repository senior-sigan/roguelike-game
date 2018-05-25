/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ENTITY_H
#define ROGUELIKE_ENTITY_H

#include "IEntity.h"
#include "FamilyTypeID.h"
#include "IComponent.h"
#include "IComponentManager.h"
#include "Component.h"
namespace ECS {
class Entity : public IEntity {
  static const EntityTypeID STATIC_ENTITY_TYPE_ID;
 protected:
  const IComponentManager *componentManager;
  ComponentID componentID;
 public:
  const EntityTypeID GetTypeID() const override;
  const EntityID GetID() const override;
  template<class C>
  C *GetComponent() override;
  template<class C, class ...P>
  C *AddComponent(P &&... params) override;
  void RemoveComponent() override;
};

template<class T>
const EntityTypeID Entity::STATIC_ENTITY_TYPE_ID = FamilyTypeID::Get();
const EntityTypeID Entity::GetTypeID() const {
    return STATIC_ENTITY_TYPE_ID;
}
const EntityID Entity::GetID() const {
    return this->componentID;
}
template<class C>
C *Entity::GetComponent() {
    return this->componentManager->GetComponent();
}
template<class C>
void Entity::RemoveComponent() {
    this->componentManager->RemoveComponent();
}
template<class C, class... P>
C *Entity::AddComponent(P &&... params) {
    return this->componentManager->AddComponent<C>(this->componentID, params);
}
}

#endif //ROGUELIKE_ENTITY_H
