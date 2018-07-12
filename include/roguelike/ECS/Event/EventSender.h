/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTSENDER_H
#define ROGUELIKE_EVENTSENDER_H

#include <ECS/Event/IEvent.h>
#include <Log/logging.h>
#include <list>

namespace ECS::Event {
class EventSender {
  friend class EventDispatcher;
  std::list<IEventPtr> events;
  LOG_INIT("EventSender");

 public:
  /**
   * Send Event.
   * @tparam TEvent type of event class
   * @tparam ARGS event constructor arguments types
   * @param eventArgs event constructor arguments
   */
  template<class TEvent, class... ARGS>
  void Send(ARGS &&... eventArgs) {
    LOG_INFO("Send even " << typeid(TEvent).name());
    auto event = std::make_shared<TEvent>(std::forward<ARGS>(eventArgs)...);
    event->after = 0;
    event->interval = 0;
    event->repeats = 0;
    event->typeIndex = std::type_index(typeid(TEvent));
    events.push_back(event);
  }

  /**
   * Send Event which will be called after [after] seconds.
   * @tparam TEvent type of event class
   * @tparam ARGS event constructor arguments types
   * @param after delay before the call in seconds
   * @param eventArgs event constructor arguments
   */
  template<class TEvent, class... ARGS>
  void SendDelayed(f64 after, ARGS &&... eventArgs) {
    auto event = std::make_shared<TEvent>(std::forward<ARGS>(eventArgs)...);
    if (after < 0) after = 0;
    event->after = after;
    event->interval = 0;
    event->repeats = 0;
    event->typeIndex = std::type_index(typeid(TEvent));
    events.push_back(event);
  }

  /**
   * Send Event which will be called after [after] seconds.
   * Event will be repeated [repeats] times with interval [interval] in seconds.
   * Use interval = -1 to indicate forever repeats.
   * TODO: how can we remove Event from the events queue??
   * @tparam TEvent type of event class
   * @tparam ARGS event constructor arguments types
   * @param after delay before the call in seconds
   * @param interval delay before the NEXT call in seconds
   * @param repeats number of repeats, -1 means forever
   * @param eventArgs event constructor arguments
   */
  template<class TEvent, class... ARGS>
  void SendInterval(f64 after, f64 interval, int64_t repeats, ARGS &&... eventArgs) {
    auto event = std::make_shared<TEvent>(std::forward<ARGS>(eventArgs)...);
    if (after < 0) after = 0;
    if (interval < 0) interval = 0;
    if (repeats < 0) repeats = -1;
    event->after = after;
    event->interval = interval;
    event->repeats = repeats;
    event->typeIndex = std::type_index(typeid(TEvent));
    events.push_back(event);
  }
};

typedef std::shared_ptr<EventSender> EventSenderPtr;
}

#endif  // ROGUELIKE_EVENTSENDER_H
