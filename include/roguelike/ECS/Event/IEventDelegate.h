/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVENTDELEGATE_H
#define ROGUELIKE_IEVENTDELEGATE_H

#include <ECS/Event/IEvent.h>
#include <ECS/Platform.h>
namespace ECS::Event {
class IEventDelegate {
 public:
  virtual void invoke(const IEventPtr &event) = 0;
  virtual EventDelegateID GetDelegateId() const = 0;
  virtual EventTypeID GetEventTypeId() const = 0;
  //  virtual bool operator==(const IEventDelegate *other) const = 0;
  virtual IEventDelegate *clone() = 0;
};

typedef std::shared_ptr<IEventDelegate> IEventDelegatePtr;
}

#endif  // ROGUELIKE_IEVENTDELEGATE_H
