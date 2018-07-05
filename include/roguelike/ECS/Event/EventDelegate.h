/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTDELEGATE_H
#define ROGUELIKE_EVENTDELEGATE_H

#include "IEventDelegate.h"
namespace ECS::Event {
template<class TReceiver, class TEvent>
inline EventDelegateID _GetDelegateId() {
//TODO: why we don't use this everywhere?
    return typeid(TReceiver).hash_code() ^ typeid(TEvent).hash_code();
}

/**
 * This class just delegates the callback call.
 * @tparam TReceiver is the target class.
 * @tparam TEvent is the method in the target class.
 */
template<class TReceiver, class TEvent>
class EventDelegate : public IEventDelegate {
  typedef void(TReceiver::*Callback)(const TEvent *const); // defines Callback

  TReceiver *receiver; // target class
  Callback callback; // callback in the target class
 public:
  EventDelegate(TReceiver *receiver, void (TReceiver::*callback)(const TEvent *const))
      : receiver(receiver), callback(callback) {}

  IEventDelegate *clone() override {
      return new EventDelegate(this->receiver, this->callback);
  }

  inline void invoke(const IEvent *event) override {
      (receiver->*callback)(reinterpret_cast<const TEvent *const>(event));
  }

  inline EventTypeID GetEventTypeId() const override {
      return TEvent::STATIC_TYPE_ID;
  }

  EventDelegateID GetDelegateId() const override {
      //TODO: why we don't use this everywhere?
      return _GetDelegateId<TReceiver, TEvent>();
  }

  bool operator==(const IEventDelegate *other) const override {
      if (other == nullptr)
          return false;
      if (this->GetDelegateId() != other->GetDelegateId())
          return false;
      auto delegate = (EventDelegate *) other;
      return ((this->callback == delegate->callback) && (this->receiver == delegate->receiver));
  }
};
}

#endif //ROGUELIKE_EVENTDELEGATE_H
