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

  EventDispatcher(EventSender *eventSender, EventListener *eventListener)
      : eventSender(eventSender), eventListener(eventListener) {}

  // Invoke all the events from the incoming queue
  void DispatchEvents() {
      //TODO: it fast enough? maybe use map?
      for (auto event: eventSender->events) {
          for (auto callback: eventListener->delegates) {
              if (callback->GetEventTypeId()==event->GetTypeId()) {
                  callback->invoke(event);
              }
          }
      }

      eventSender->events.clear();
  }
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
