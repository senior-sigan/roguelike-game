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
};
}
#endif  // ROGUELIKE_ENTITY_H
