/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_COMPONENT_H
#define ROGUELIKE_COMPONENT_H

#include "IComponent.h"
#include "FamilyTypeID.h"
namespace ECS {

template<class TComponent>
class Component : public ECS::IComponent {
  friend class ComponentManager;
  static const ComponentTypeID STATIC_TYPE_ID;
 public:
  const ComponentTypeID GetTypeID() const override {
      return STATIC_TYPE_ID;
  }
};

template<class TComponent>
const ECS::ComponentTypeID
    ECS::Component<TComponent>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::IComponent>::Get<TComponent>();
}
#endif //ROGUELIKE_COMPONENT_H
