/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENTDELEGATE_H
#define ROGUELIKE_EVENTDELEGATE_H

#include <ECS/Event/IEventDelegate.h>
namespace ECS::Event {
template<class TReceiver, class TEvent>
inline EventDelegateID _GetDelegateId() {
  return typeid(TReceiver).hash_code() ^ typeid(TEvent).hash_code();
}

/**
 * This class just delegates the callback call.
 * @tparam TReceiver is the target class.
 * @tparam TEvent is the method in the target class.
 */
template<class TReceiver, class TEvent>
class EventDelegate : public IEventDelegate {
  typedef void (TReceiver::*Callback)(const std::shared_ptr<TEvent> &);  // defines Callback

  TReceiver *receiver;  // target class
  Callback callback;    // callback in the target class

 public:
  EventDelegate(TReceiver *receiver, void (TReceiver::*callback)(const std::shared_ptr<TEvent> &))
      : receiver(receiver), callback(callback) {}

  IEventDelegate *clone() override {
    return new EventDelegate(this->receiver, this->callback);
  }

  void invoke(const IEventPtr &event) override {
    (receiver->*callback)(std::static_pointer_cast<TEvent>(event));
  }

  EventTypeID GetEventTypeId() const override {
    return std::type_index(typeid(TEvent));
  }

  EventDelegateID GetDelegateId() const override {
    // TODO: why we don't use this everywhere?
    return _GetDelegateId<TReceiver, TEvent>();
  }

  //  bool operator==(const IEventDelegate *other) const override {
  //    if (other == nullptr) return false;
  //    if (this->GetDelegateId() != other->GetDelegateId()) return false;
  //    auto delegate = reinterpret_cast<EventDelegate *>(other);
  //    return ((this->callback == delegate->callback) && (this->receiver == delegate->receiver));
  //  }
};
}

#endif  // ROGUELIKE_EVENTDELEGATE_H
