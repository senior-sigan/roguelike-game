/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTLISTENER_H
#define ROGUELIKE_EVENTLISTENER_H

#include "IEventDelegate.h"
#include "list"
#include "EventDelegate.h"
namespace ECS::Event {
class EventListener {
  friend class EventDispatcher;
  std::list<IEventDelegate *> delegates;
 public:
  template<class TReceiver, class TEvent>
  inline void RegisterListener(TReceiver *receiver, void(TReceiver::*callback)(const TEvent *const)) {
      auto delegate = new EventDelegate<TReceiver, TEvent>(receiver, callback);
      delegates.push_back(delegate);
  };

  template<class TReceiver, class TEvent>
  inline void UnregisterListener(void(TReceiver::*Callback)(const TEvent *const)) {
      for (auto delegate: delegates) {
          if (delegate->GetDelegateId()==_GetDelegateId<TReceiver, TEvent>()) {
              this->delegates.remove_if([&](const IEventDelegate *other) -> bool {
                return other->operator==(delegate);
              });
          }
      }
  };
};
}

#endif //ROGUELIKE_EVENTLISTENER_H
