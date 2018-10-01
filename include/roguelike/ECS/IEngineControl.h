/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#ifndef ROGUELIKE_IENGINECONTROL_H
#define ROGUELIKE_IENGINECONTROL_H

#include <memory>

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
  virtual std::shared_ptr<Event::EventDispatcher> GetEventHandler() const = 0;
  virtual ~IEngineControl() = default;
};
}

#endif  // ROGUELIKE_IENGINECONTROL_H
