/**
 * Created by Илья Сиганов on 30.05.2018.
 */

#ifndef ROGUELIKE_EVENTHANDLER_H
#define ROGUELIKE_EVENTHANDLER_H

namespace ECS::Event {

class EventDispatcher {
 public:
  // Invoke all the events from the incoming queue
  void DispatchEvents() const {}
};

class EventListener {
 public:
  template<class TEvent, class TCallback>
  inline void RegisterListener(void(TCallback::*Callback)(const TEvent *const)) {};
  template<class TEvent, class TCallback>
  inline void UnregisterListener(void(TCallback::*Callback)(const TEvent *const)) {};
};

class EventSender {
  // Send event, meaning add event to the queue
  template<class TEvent, class... ARGS>
  void Send(ARGS &&... eventArgs) const {}
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
