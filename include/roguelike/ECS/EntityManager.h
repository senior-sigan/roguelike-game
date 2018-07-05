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
  ComponentManagerPtr componentManager;

 public:
  std::unordered_map<EntityID, std::shared_ptr<IEntity>> container;
  std::set<EntityID> toDelete;

  explicit EntityManager(const ComponentManagerPtr &componentManager) : componentManager(componentManager) {
    LOG_INFO("EntityManager was initialized");
  }

  template<class TEntity, class... TParam>
  EntityID Create(TParam &&... params) {
    auto entity = CreateAndGet<TEntity>(std::forward<TParam>(params)...);
    return entity->GetID();
  }

  template<class TEntity, class... TParam>
  std::shared_ptr<TEntity> CreateAndGet(TParam &&... params) {
    auto entity = std::make_shared<TEntity>(std::forward<TParam>(params)...);
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

  void DestroyAllEntities() {
    toDelete.clear();
    container.clear();
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

  std::shared_ptr<IEntity> Get(EntityID id) {
    return container[id];
  }
};

typedef std::shared_ptr<EntityManager> EntityManagerPtr;
}

#endif  // ROGUELIKE_ENTITYMANAGER_H
