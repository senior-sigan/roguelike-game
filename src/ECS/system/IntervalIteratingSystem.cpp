/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <ECS/system/IntervalIteratingSystem.h>

void ECS::IntervalIteratingSystem::_PreUpdate(double dt) {
  PreUpdate(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PreProcessEntity(entity.second, dt);
    }
  }
  if (currentTime < 0) currentTime = 0;
  if (dt > 0) currentTime += dt;  // Every PRE update increment timer
  if (currentTime >= interval) {
    _PreUpdateInterval(currentTime);
  }
}
void ECS::IntervalIteratingSystem::_Update(double dt) {
  Update(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      ProcessEntity(entity.second, dt);
    }
  }
  if (currentTime >= interval) {
    _UpdateInterval(currentTime);
  }
}
void ECS::IntervalIteratingSystem::_PostUpdate(double dt) {
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PostProcessEntity(entity.second, dt);
    }
  }
  PostUpdate(dt);
  if (currentTime >= interval) {
    _PostUpdateInterval(currentTime);
    currentTime -= interval;  // Every POST update decrement timer
  }
}
void ECS::IntervalIteratingSystem::_UpdateInterval(double dt) {
  UpdateInterval(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      ProcessEntityInterval(entity.second, dt);
    }
  }
}
void ECS::IntervalIteratingSystem::_PostUpdateInterval(double dt) {
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PostProcessEntityInterval(entity.second, dt);
    }
  }
  PostUpdateInterval(dt);
}
void ECS::IntervalIteratingSystem::_PreUpdateInterval(double dt) {
  PreUpdateInterval(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PreProcessEntityInterval(entity.second, dt);
    }
  }
}
ECS::IntervalIteratingSystem::IntervalIteratingSystem(const double interval) : interval(interval) {
  currentTime = 0;
}
