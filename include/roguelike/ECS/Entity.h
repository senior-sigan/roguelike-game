/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_ENTITY_H
#define ROGUELIKE_ENTITY_H

#include "ECS/FamilyTypeID.h"
#include "ECS/IEntity.h"
namespace ECS {

template<class TEntity>
class Entity : public IEntity {
  friend class SystemManager;
  static const EntityTypeID STATIC_ENTITY_TYPE_ID;

 public:
  EntityTypeID GetTypeID() const override {
    return STATIC_ENTITY_TYPE_ID;
  }
  const char *GetTypeName() const override {
    return typeid(TEntity).name();
  }
};

template<class TEntity>
const ECS::EntityTypeID ECS::Entity<TEntity>::STATIC_ENTITY_TYPE_ID =
    ECS::Internal::FamilyTypeID<ECS::IEntity>::Get<TEntity>();
}

#endif  // ROGUELIKE_ENTITY_H
