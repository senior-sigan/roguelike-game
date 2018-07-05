/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include "ECS/Event/IEvent.h"

namespace ECS::Event {
void IEvent::update(double deltaTime) {
    currentTime += deltaTime;
    shouldUpdate = true;
}
void IEvent::registerCall() {
    if (shouldUpdate) {
        wasCalled = true;
        currentTime = 0;
        calls += 1;
        shouldUpdate = false;
    }
}
bool IEvent::isToDelete() const {
    if (repeats == -1) return false;
    return calls > repeats;
}
bool IEvent::isInvokableNow() const {
    return isFitInDelay() && isFitInRepeats();
}
bool IEvent::isFitInDelay() const {
    if (wasCalled) return interval <= currentTime;
    return after <= currentTime;
}
bool IEvent::isFitInRepeats() const {
    if (repeats == -1) return true;
    return calls - repeats <= 0;
}
}