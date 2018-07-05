/**
 * Created by Илья Сиганов on 03.07.2018.
 */
#include "game/systems/ItemGatheringSystem.h"
#include <game/components/BoxColliderComponent.h>
#include <game/components/GathererComponent.h>
#include <game/components/ItemComponent.h>
#include <game/components/WorthComponent.h>

void ItemGatheringSystem::ProcessEntity(ECS::IEntity* entity, double dt) {
  auto bcc = entity->GetComponent<BoxColliderComponent>();
  auto wc = entity->GetComponent<WorthComponent>();
  for (auto collider : bcc->GetCollisions()) {
    if (collider->HasComponent<GathererComponent>()) {
      collider->GetComponent<GathererComponent>()->SaveCache(wc->GetValue());
      GetEntityManager()->Destroy(entity->GetID());
    }
  }
}
bool ItemGatheringSystem::FamilyFilter(const ECS::IEntity* entity) const {
  return entity->HasComponent<ItemComponent>() && entity->HasComponent<BoxColliderComponent>();
}
