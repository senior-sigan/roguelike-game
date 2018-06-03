/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVENTDELEGATE_H
#define ROGUELIKE_IEVENTDELEGATE_H

#include "../Platform.h"
#include "IEvent.h"
namespace ECS::Event {
class IEventDelegate {
 public:
  virtual inline void invoke(const IEvent *event) = 0;
  virtual inline EventDelegateID GetDelegateId() const = 0;
  virtual inline EventTypeID GetEventTypeId() const = 0;
  virtual bool operator==(const IEventDelegate *other) const = 0;
  virtual IEventDelegate *clone() = 0;
};
}

#endif //ROGUELIKE_IEVENTDELEGATE_H
