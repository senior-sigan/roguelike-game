/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTLISTENER_H
#define ROGUELIKE_EVENTLISTENER_H

#include <ECS/Event/EventDelegate.h>
#include <ECS/Event/IEventDelegate.h>
#include <list>
namespace ECS::Event {
class EventListener {
  friend class EventDispatcher;
  std::list<IEventDelegatePtr> delegates;

 public:
  template<class TReceiver, class TEvent>
  inline void RegisterListener(TReceiver *receiver, void (TReceiver::*callback)(const TEvent *const)) {
    auto delegate = std::shared_ptr(new EventDelegate<TReceiver, TEvent>(receiver, callback));
    delegates.push_back(delegate);
  }

  template<class TReceiver, class TEvent>
  inline void UnregisterListener(void (TReceiver::*Callback)(const TEvent *const)) {
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
