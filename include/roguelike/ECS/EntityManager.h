/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ENTITYMANAGER_H
#define ROGUELIKE_ENTITYMANAGER_H

#include <set>
#include "ECS/IEntity.h"
#include "ECS/Platform.h"
namespace ECS {
class EntityManager {
  friend class SystemManager;
  LOG_INIT("EntityManager");
  EntityID currentID = 0;
  ComponentManager *componentManager;

 public:
  std::unordered_map<EntityID, IEntity *> container;
  std::set<EntityID> toDelete;

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

  /**
   * Method mark the entity to be deleted later, when engine is able to remove objects.
   * @param id is entity id.
   */
  void Destroy(EntityID id) {
    toDelete.emplace(id);
  }

  /**
   * Completely removes all marked to delete entities with associated components.
   */
  void SweepDeleted() {
    for (auto key : toDelete) {
      auto entity = container[key];
      if (!entity) continue;
      entity->RemoveAllComponents();
      container.erase(key);
    }
    toDelete.clear();
  }

  IEntity *Get(EntityID id) {
    return container[id];
  }
};
}

#endif  // ROGUELIKE_ENTITYMANAGER_H
