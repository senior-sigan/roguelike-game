/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/Event/EventDispatcher.h>

namespace ECS::Event {
void EventDispatcher::DispatchEvents(double deltaTime) {
  // TODO: is it fast enough? maybe use map?
  for (auto event : eventSender->events) {
    event->update(deltaTime);
    for (auto callback : eventListener->delegates) {
      if (callback->GetEventTypeId() == std::type_index(typeid(event)) && event->isInvokableNow()) {
        callback->invoke(event);
        event->registerCall();
      }
    }
  }

  eventSender->events.remove_if([&](const IEvent* event) -> bool { return event->isToDelete(); });
}
EventDispatcher::EventDispatcher(EventSender* eventSender, EventListener* eventListener)
    : eventSender(eventSender), eventListener(eventListener) {}
}