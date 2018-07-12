/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTLISTENER_H
#define ROGUELIKE_EVENTLISTENER_H

#include <ECS/Event/EventDelegate.h>
#include <ECS/Event/IEventDelegate.h>
#include <Log/logging.h>
#include <list>

namespace ECS::Event {
class EventListener {
  friend class EventDispatcher;
  std::list<IEventDelegatePtr> delegates;
  LOG_INIT("EventListener");

 public:
  template<class TReceiver, class TEvent>
  void RegisterListener(TReceiver *receiver, void (TReceiver::*callback)(const std::shared_ptr<TEvent> &)) {
    auto delegate =
        std::shared_ptr<EventDelegate<TReceiver, TEvent>>(new EventDelegate<TReceiver, TEvent>(receiver, callback));
    delegates.push_back(delegate);
    LOG_INFO("Registered [" << typeid(TEvent).name() << "," << typeid(TReceiver).name() << "] listener");
  }

  template<class TReceiver, class TEvent>
  void UnregisterListener(void (TReceiver::*Callback)(const std::shared_ptr<TEvent> &)) {
    for (const auto &delegate : delegates) {
      if (delegate->GetDelegateId() == _GetDelegateId<TReceiver, TEvent>()) {
        this->delegates.remove_if([&](const IEventDelegatePtr other) -> bool { return delegate.get() == other.get(); });
      }
    }
  }
};

typedef std::shared_ptr<EventListener> EventListenerPtr;
}

#endif  // ROGUELIKE_EVENTLISTENER_H
