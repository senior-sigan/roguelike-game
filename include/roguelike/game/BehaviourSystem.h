/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_BEHAVIOURSYSTEM_H
#define ROGUELIKE_BEHAVIOURSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include "BehaviourComponent.h"

/**
 * A system that responsible fot controlling behaviour components.
 */

class BehaviourSystem : public ECS::IteratingSystem<BehaviourSystem> {
 public:
  void PreProcessEntity(ECS::IEntity *entity, double dt) override {
      entity->GetComponent<BehaviourComponent>()->behaviour->PreUpdate(dt);
  }
  void ProcessEntity(ECS::IEntity *entity, double dt) override {
      entity->GetComponent<BehaviourComponent>()->behaviour->Update(dt);
  }
  void PostProcessEntity(ECS::IEntity *entity, double dt) override {
      entity->GetComponent<BehaviourComponent>()->behaviour->PostUpdate(dt);
  }
  const bool FamilyFilter(ECS::IEntity *entity) const override {
      return entity->HasComponent<BehaviourComponent>();
  }
};

#endif //ROGUELIKE_BEHAVIOURSYSTEM_H
