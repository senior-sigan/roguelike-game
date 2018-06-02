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
  void DispatchEvents(float deltaTime) {
      //TODO: is it fast enough? maybe use map?
      for (auto event: eventSender->events) {
          event->update(deltaTime);
          for (auto callback: eventListener->delegates) {
              if (callback->GetEventTypeId()==event->GetTypeId() && event->isInvokableNow()) {
                  callback->invoke(event);
                  event->registerCall();
              }
          }
      }

      eventSender->events.remove_if([&](const IEvent const *event) -> bool {
        return event->isToDelete();
      });
  }
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
