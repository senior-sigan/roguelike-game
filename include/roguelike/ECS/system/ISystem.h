/**
 * Created by Илья Сиганов on 29.05.2018.
 */

#ifndef ROGUELIKE_ISYSTEM_H
#define ROGUELIKE_ISYSTEM_H

#include <vector>
#include "ECS/Platform.h"
#include "ECS/Event/EventDispatcher.h"
#include "ECS/IEngineControl.h"
#include "ECS/IEntity.h"
namespace ECS {

class ISystem {
  friend class SystemManager;
  EntityManager *entityManager{};
  IEngineControl *engineControl{};
 protected:
  Event::EventSender *eventSender{};
  Event::EventListener *eventListener{};
 public:
  const IEngineControl *GetEngineControl() const {
      return engineControl;
  }
  const EntityManager* GetEntityManager() const {
      return entityManager;
  }

  virtual const SystemPriority GetSystemPriority() const {
      return 0;
  };
  virtual const SystemTypeID GetTypeID() const = 0;

  virtual void PreUpdate(double dt) {};
  virtual void Update(double dt) {};
  virtual void PostUpdate(double dt) {};

  virtual void OnCreated() {};
};
}

#endif //ROGUELIKE_ISYSTEM_H
