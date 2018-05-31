/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ISYSTEM_H
#define ROGUELIKE_ISYSTEM_H

#include <vector>
#include "Platform.h"
#include "Event/EventDispatcher.h"
namespace ECS {

class ISystem {
  friend class SystemManager;
 public:
  virtual const SystemPriority GetSystemPriority() const {
      return 0;
  };
  virtual const SystemTypeID GetTypeID() const = 0;

  virtual void PreUpdate(IEntity *entity, float dt) {};
  virtual void Update(IEntity *entity, float dt) {};
  virtual void PostUpdate(IEntity *entity, float dt) {};

  /**
   * Filter and pass only IEntities that satisfy the predicate.
   * @return true if satisfy and false otherwise.
   */
  virtual const bool FamilyFilter(IEntity *entity) const {
      return false;
  };

  virtual void OnCreated() {};
};
}

#endif //ROGUELIKE_ISYSTEM_H
