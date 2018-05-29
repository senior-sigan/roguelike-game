/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ENTITYMANAGER_H
#define ROGUELIKE_ENTITYMANAGER_H

#include "Platform.h"
#include "IEntity.h"
namespace ECS {
class EntityManager {
  EntityID currentID = 0;
 public:
  template<class TEntity, class... TParam>
  EntityID Create(TParam &&... params) {
      //TODO: allocation new Entity with ID, Save the pointer to it, return this ID
      auto entity = CreateAndGet<TEntity>(std::forward<TParam>(params)...);
      return entity->GetID();
  }

  template<class TEntity, class... TParam>
  TEntity *CreateAndGet(TParam &&... params) {
      //TODO: allocation new Entity with ID, Save the pointer to it, return this ID
      auto entity = new TEntity(std::forward<TParam>(params)...);
      entity->entityID = currentID++;
      return entity;
  }

  void Destroy(EntityID id) {
      //TODO: find entity by id and destroy it
  }

  inline IEntity *Get(EntityID id) {
      // TODO: find entity by id and return pointer
      return nullptr;
  }
};
}

#endif //ROGUELIKE_ENTITYMANAGER_H
