/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <ECS/system/IteratingSystem.h>

void ECS::IteratingSystem::_PreUpdate(f64 dt) {
  PreUpdate(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PreProcessEntity(entity.second, dt);
    }
  }
}
void ECS::IteratingSystem::_Update(f64 dt) {
  Update(dt);
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      ProcessEntity(entity.second, dt);
    }
  }
}
void ECS::IteratingSystem::_PostUpdate(f64 dt) {
  for (auto entity : GetEntityManager()->container) {
    if (FamilyFilter(entity.second)) {
      PostProcessEntity(entity.second, dt);
    }
  }
  PostUpdate(dt);
}
