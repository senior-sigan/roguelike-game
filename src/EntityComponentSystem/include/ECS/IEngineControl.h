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
  virtual EntityManager *GetEntityManager() const = 0;
  virtual ComponentManager *GetComponentManager() const = 0;
  virtual SystemManager *GetSystemManager() const = 0;
  virtual Event::EventDispatcher *GetEventHandler() const = 0;
};
}

#endif //ROGUELIKE_IENGINECONTROL_H
