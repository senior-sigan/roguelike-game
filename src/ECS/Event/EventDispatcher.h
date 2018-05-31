/**
 * Created by Илья Сиганов on 30.05.2018.
 */

#ifndef ROGUELIKE_EVENTHANDLER_H
#define ROGUELIKE_EVENTHANDLER_H

#include <list>
namespace ECS::Event {

class IEvent {

};

class EventSender {
  friend class EventDispatcher;
 public:
  // Send event, meaning add event to the queue
  template<class TEvent, class... ARGS>
  void Send(ARGS &&... eventArgs) const {}
};

class IEventDelegate {
 public:
  virtual inline void invoke(const IEvent *event) = 0;
  virtual inline EventDelegateID GetDelegateId() const = 0;
  virtual inline EventTypeID GetEventTypeId() const = 0;
  virtual bool operator==(const IEventDelegate *other) const = 0;
  virtual IEventDelegate *clone() = 0;
};

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
  EventDelegate(TReceiver *receiver, void (*callback)(const TEvent *const))
      : receiver(receiver), callback(callback) {}

  IEventDelegate *clone() override {
      return new EventDelegate(this->receiver, this->callback);
  }

  inline void invoke(const IEvent *const e) override {
      (receiver->*callback)(reinterpret_cast<const TEvent *const>(e));
  }

  inline EventTypeID GetEventTypeId() const override {
      return TEvent::STATIC_TYPE_ID;
  }

  EventDelegateID GetDelegateId() const override {
      //TODO: why we don't use this everywhere?
      return _GetDelegateId<TReceiver, TEvent>();
  }

  bool operator==(const IEventDelegate *other) const override {
      if (other==nullptr)
          return false;
      if (this->GetDelegateId()!=other->GetDelegateId())
          return false;
      auto delegate = (EventDelegate *) other;
      return ((this->callback==delegate->callback) && (this->receiver==delegate->receiver));
  }
};

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
  inline void UnregisterListener(TReceiver *receiver, void(TReceiver::*Callback)(const TEvent *const)) {
      for (auto delegate: delegates) {
          if (delegate->GetDelegateId()==_GetDelegateId<TReceiver, TEvent>()) {
              this->delegates.remove_if([&](const IEventDelegate *other) {
                return other->operator==(delegate);
              });
          }
      }
  };
};

class EventDispatcher {
  EventSender eventSender;
  EventListener eventListener;

 public:
  // Invoke all the events from the incoming queue
  void DispatchEvents() const {}
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
