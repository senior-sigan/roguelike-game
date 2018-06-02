/**
 * Created by Илья Сиганов on 31.05.2018.
 */

#ifndef ROGUELIKE_IEVEMT_H
#define ROGUELIKE_IEVEMT_H

namespace ECS::Event {
class IEvent {
  friend class EventSender;
  friend class EventDispatcher;

  long repeats = 0; // constant
  double after = 0; // constant
  double interval = 0; // constant

  bool wasCalled = false;
  double currentTime = 0;
  long calls = 0;
  bool shouldUpdate = true;

  /**
   * Event tracks time inside to notify dispatcher
   * when it's ready for delivery when [after] and [interval] is used.
   * @param deltaTime in seconds
   */
  void update(double deltaTime) {
      currentTime += deltaTime;
      shouldUpdate = true;
  }

  void registerCall() {
      if (shouldUpdate) {
          wasCalled = true;
          currentTime = 0;
          calls += 1;
          shouldUpdate = false;
      }
  }

  bool isToDelete() const {
      if (repeats==-1) return false;
      return calls > repeats;
  }

  bool isInvokableNow() const {
      return isFitInDelay() && isFitInRepeats();
  }

  bool isFitInDelay() const {
      if (wasCalled) return interval <= currentTime;
      return after <= currentTime;
  }

  bool isFitInRepeats() const {
      if (repeats==-1) return true;
      return calls - repeats <= 0;
  }
 public:
  virtual const EventTypeID GetTypeId() const = 0;
};
}

#endif //ROGUELIKE_IEVEMT_H
