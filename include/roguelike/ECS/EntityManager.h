/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ENTITYMANAGER_H
#define ROGUELIKE_ENTITYMANAGER_H

#include <unordered_map>
#include "Platform.h"
#include "IEntity.h"
namespace ECS {
class EntityManager {
  friend class SystemManager;
  LOG_INIT("EntityManager");
  std::unordered_map<EntityID, IEntity *> container;
  EntityID currentID = 0;
  ComponentManager *componentManager;
 public:
  explicit EntityManager(ComponentManager *componentManager) : componentManager(componentManager) {
      LOG_INFO("EntityManager was initialized");
  }

  template<class TEntity, class... TParam>
  EntityID Create(TParam &&... params) {
      auto entity = CreateAndGet<TEntity>(std::forward<TParam>(params)...);
      return entity->GetID();
  }

  template<class TEntity, class... TParam>
  TEntity *CreateAndGet(TParam &&... params) {
      auto entity = new TEntity(std::forward<TParam>(params)...);
      entity->entityID = currentID++;
      entity->componentManager = this->componentManager;
      container[entity->entityID] = entity;
      entity->OnCreated();
      LOG_INFO("Entity was created: " << typeid(TEntity).name());
      return entity;
  }

  void Destroy(EntityID id) {
      container.erase(id);
  }

  IEntity *Get(EntityID id) {
      return container[id];
  }
};
}

#endif //ROGUELIKE_ENTITYMANAGER_H
