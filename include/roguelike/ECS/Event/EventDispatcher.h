/**
 * Created by Илья Сиганов on 30.05.2018.
 */

#ifndef ROGUELIKE_EVENTHANDLER_H
#define ROGUELIKE_EVENTHANDLER_H

#include <ECS/Event/EventListener.h>
#include <ECS/Event/EventSender.h>
namespace ECS::Event {

class EventDispatcher {
 public:
  EventSenderPtr eventSender;
  EventListenerPtr eventListener;

  EventDispatcher(const EventSenderPtr& eventSender, const EventListenerPtr& eventListener);

  // Invoke all the events from the incoming queue
  void DispatchEvents(double deltaTime);
};

typedef std::shared_ptr<EventDispatcher> EventDispatcherPtr;
}

#endif  // ROGUELIKE_EVENTHANDLER_H
