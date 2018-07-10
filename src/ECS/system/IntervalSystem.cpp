/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <ECS/system/IntervalSystem.h>

void ECS::IntervalSystem::_PreUpdate(f64 dt) {
  PreUpdate(dt);
  if (currentTime < 0) currentTime = 0;
  if (dt > 0) currentTime += dt;  // Every PRE update increment timer
  if (currentTime >= interval) {
    PreUpdateInterval(currentTime);
  }
}
void ECS::IntervalSystem::_Update(f64 dt) {
  Update(dt);
  if (currentTime >= interval) {
    UpdateInterval(currentTime);
  }
}
void ECS::IntervalSystem::_PostUpdate(f64 dt) {
  PostUpdate(dt);
  if (currentTime >= interval) {
    PostUpdateInterval(currentTime);
    currentTime -= interval;  // Every POST update decrement timer
  }
}
ECS::IntervalSystem::IntervalSystem(const f64 interval) : interval(interval) {
  currentTime = 0;
}
ECS::IntervalSystem::~IntervalSystem() {
  currentTime = 0;
}
