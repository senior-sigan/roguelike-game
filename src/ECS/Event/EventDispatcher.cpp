/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/Event/EventDispatcher.h>

namespace ECS::Event {
void EventDispatcher::DispatchEvents(f64 deltaTime) {
  // TODO: is it fast enough? maybe use map?
  for (const auto &event : eventSender->events) {
    event->update(deltaTime);
    for (const auto &callback : eventListener->delegates) {
      auto cbEvId = callback->GetEventTypeId();
      auto evId = event->GetEventTypeId();
      if (cbEvId == evId  && event->isInvokableNow()) {
        callback->invoke(event);
        event->registerCall();
      }
    }
  }

  eventSender->events.remove_if([&](const IEventPtr &event) -> bool { return event->isToDelete(); });
}
EventDispatcher::EventDispatcher(const EventSenderPtr &eventSender, const EventListenerPtr &eventListener)
    : eventSender(eventSender), eventListener(eventListener) {}
}