/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTSENDER_H
#define ROGUELIKE_EVENTSENDER_H

#include "list"
#include "IEvent.h"
namespace ECS::Event {
class EventSender {
  friend class EventDispatcher;
  std::list<IEvent*> events;
 public:
  // Send event, meaning add event to the queue
  template<class TEvent, class... ARGS>
  void Send(ARGS &&... eventArgs) {
      auto event = new TEvent(std::forward<ARGS>(eventArgs)...);
      events.push_back(event);
  }
};
}

#endif //ROGUELIKE_EVENTSENDER_H
