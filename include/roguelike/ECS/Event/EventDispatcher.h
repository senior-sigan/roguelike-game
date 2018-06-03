/**
 * Created by Илья Сиганов on 30.05.2018.
 */

#ifndef ROGUELIKE_EVENTHANDLER_H
#define ROGUELIKE_EVENTHANDLER_H

#include "EventSender.h"
#include "EventListener.h"
namespace ECS::Event {

class EventDispatcher {
 public:
  EventSender *eventSender;
  EventListener *eventListener;

  EventDispatcher(EventSender *eventSender, EventListener *eventListener);

  // Invoke all the events from the incoming queue
  void DispatchEvents(double deltaTime);
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
