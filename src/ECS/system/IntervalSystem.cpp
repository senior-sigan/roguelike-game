/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <ECS/system/IntervalSystem.h>

void ECS::IntervalSystem::_PreUpdate(double dt) {
  PreUpdate(dt);
  if (currentTime < 0) currentTime = 0;
  if (dt > 0) currentTime += dt;  // Every PRE update increment timer
  if (currentTime >= interval) {
    PreUpdateInterval(currentTime);
  }
}
void ECS::IntervalSystem::_Update(double dt) {
  Update(dt);
  if (currentTime >= interval) {
    UpdateInterval(currentTime);
  }
}
void ECS::IntervalSystem::_PostUpdate(double dt) {
  PostUpdate(dt);
  if (currentTime >= interval) {
    PostUpdateInterval(currentTime);
    currentTime -= interval;  // Every POST update decrement timer
  }
}
ECS::IntervalSystem::IntervalSystem(const double interval) : interval(interval) {
  currentTime = 0;
}
