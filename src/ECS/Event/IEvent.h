/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVEMT_H
#define ROGUELIKE_IEVEMT_H

namespace ECS::Event {
class IEvent {
 public:
  virtual const EventTypeID GetTypeId() const = 0;
};
}

#endif //ROGUELIKE_IEVEMT_H
