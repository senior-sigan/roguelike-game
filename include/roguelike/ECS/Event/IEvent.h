/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVEMT_H
#define ROGUELIKE_IEVEMT_H

#include <ECS/Platform.h>

namespace ECS::Event {
class IEvent {
  friend class EventSender;
  friend class EventDispatcher;

  int64_t repeats = 0;  // constant
  double after = 0;     // constant
  double interval = 0;  // constant

  bool wasCalled = false;
  double currentTime = 0;
  int64_t calls = 0;
  bool shouldUpdate = true;

  /**
   * Event tracks time inside to notify dispatcher
   * when it's ready for delivery when [after] and [interval] is used.
   * @param deltaTime in seconds
   */
  void update(double deltaTime);

  void registerCall();

  bool isToDelete() const;

  bool isInvokableNow() const;

  bool isFitInDelay() const;

  bool isFitInRepeats() const;

 public:
  virtual ECS::EventTypeID GetTypeId() const = 0;
};
}

#endif  // ROGUELIKE_IEVEMT_H
