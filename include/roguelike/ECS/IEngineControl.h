/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#ifndef ROGUELIKE_IENGINECONTROL_H
#define ROGUELIKE_IENGINECONTROL_H

namespace ECS {
class EntityManager;
class ComponentManager;
class SystemManager;
namespace Event {
class EventDispatcher;
}

class IEngineControl {
 public:
  virtual void Stop() = 0;
  virtual std::shared_ptr<EntityManager> GetEntityManager() const = 0;
  virtual std::shared_ptr<ComponentManager> GetComponentManager() const = 0;
  virtual std::shared_ptr<SystemManager> GetSystemManager() const = 0;
  virtual Event::EventDispatcherPtr GetEventHandler() const = 0;
};
}

#endif  // ROGUELIKE_IENGINECONTROL_H
