/**
 * Created by Илья Сиганов on 30.05.2018.
 */

#ifndef ROGUELIKE_EVENTHANDLER_H
#define ROGUELIKE_EVENTHANDLER_H

namespace ECS::Event {

class EventHandler {
 public:
  void DispatchEvents() const {

  }
  template<class E, class... ARGS>
  void Send(ARGS &&... eventArgs) const {}
};
}

#endif //ROGUELIKE_EVENTHANDLER_H
