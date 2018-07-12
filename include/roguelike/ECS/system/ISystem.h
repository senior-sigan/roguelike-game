/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ISYSTEM_H
#define ROGUELIKE_ISYSTEM_H

#include <ECS/EntityManager.h>
#include <ECS/Event/EventDispatcher.h>
#include <ECS/IEngineControl.h>
#include <ECS/IEntity.h>
#include <ECS/Platform.h>
#include <ECS/system/IUpdate.h>
#include <vector>
namespace ECS {

class ISystem : public IUpdate {
  friend class SystemManager;
  EntityManagerPtr entityManager;
  IEngineControl *engineControl;
  Event::EventSenderPtr eventSender;
  Event::EventListenerPtr eventListener;

 public:
  IEngineControl *GetEngineControl() const {
    return engineControl;
  }
  EntityManagerPtr GetEntityManager() const {
    return entityManager;
  }
  Event::EventSenderPtr GetEventSender() const {
    return eventSender;
  }
  Event::EventListenerPtr GetEventListener() const {
    return eventListener;
  }

  virtual SystemPriority GetSystemPriority() const {
    return 0;
  }
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

  virtual ~ISystem() = default;
};

typedef std::shared_ptr<ISystem> ISystemPtr;
}

#endif  // ROGUELIKE_ISYSTEM_H
