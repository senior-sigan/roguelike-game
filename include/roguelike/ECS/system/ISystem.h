/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ISYSTEM_H
#define ROGUELIKE_ISYSTEM_H

#include <ECS/Event/EventDispatcher.h>
#include <ECS/IEngineControl.h>
#include <ECS/IEntity.h>
#include <ECS/Platform.h>
#include <ECS/system/IUpdate.h>
#include <vector>
namespace ECS {

class ISystem : public IUpdate {
  friend class SystemManager;
  EntityManager *entityManager{};
  IEngineControl *engineControl{};

 protected:
  Event::EventSender *eventSender{};
  Event::EventListener *eventListener{};

 public:
  IEngineControl *GetEngineControl() const {
    return engineControl;
  }
  EntityManager *GetEntityManager() const {
    return entityManager;
  }

  virtual SystemPriority GetSystemPriority() const {
    return 0;
  }
  virtual SystemTypeID GetTypeID() const = 0;
  virtual void OnCreated() {}
  virtual void OnDestroy() {}

  bool operator<(const ISystem &rhs) const {
    return GetSystemPriority() < rhs.GetSystemPriority();
  }
  bool operator>(const ISystem &rhs) const {
    return rhs < *this;
  }
  bool operator<=(const ISystem &rhs) const {
    return !(rhs < *this);
  }
  bool operator>=(const ISystem &rhs) const {
    return !(*this < rhs);
  }
};
}

#endif  // ROGUELIKE_ISYSTEM_H
