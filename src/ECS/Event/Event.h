/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_EVENT_H
#define ROGUELIKE_EVENT_H

#include "IEvent.h"
#include "../FamilyTypeID.h"
namespace ECS::Event {

template<class TEvent>
class Event : public IEvent {
 public:
  static const EventTypeID STATIC_TYPE_ID;
  const EventTypeID GetTypeId() const override {
      return STATIC_TYPE_ID;
  }
};
}

template<class TEvent>
const ECS::EventTypeID
    ECS::Event::Event<TEvent>::STATIC_TYPE_ID = ECS::Internal::FamilyTypeID<ECS::Event::IEvent>::Get<TEvent>();

#endif //ROGUELIKE_EVENT_H
