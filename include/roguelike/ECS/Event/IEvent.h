/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVEMT_H
#define ROGUELIKE_IEVEMT_H

#include <ECS/Platform.h>
#include <core/types.h>

namespace ECS::Event {
class IEvent {
  friend class EventSender;
  friend class EventDispatcher;

  i64 repeats = 0;   // constant
  f64 after = 0;     // constant
  f64 interval = 0;  // constant

  bool wasCalled = false;
  f64 currentTime = 0;
  i64 calls = 0;
  bool shouldUpdate = true;

  std::type_index typeIndex = std::type_index(typeid(IEvent));

  /**
   * Event tracks time inside to notify dispatcher
   * when it's ready for delivery when [after] and [interval] is used.
   * @param deltaTime in seconds
   */
  void update(f64 deltaTime);

  void registerCall();

  bool isToDelete() const;

  bool isInvokableNow() const;

  bool isFitInDelay() const;

  bool isFitInRepeats() const;

  std::type_index GetEventTypeId() const {
    return typeIndex;
  }
};

typedef std::shared_ptr<IEvent> IEventPtr;
}

#endif  // ROGUELIKE_IEVEMT_H
