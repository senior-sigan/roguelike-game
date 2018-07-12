/**
 * Created by Илья Сиганов on 03.07.2018.
 */
#include "game/systems/ItemGatheringSystem.h"
#include <game/components/BoxColliderComponent.h>
#include <game/components/GathererComponent.h>
#include <game/components/ItemComponent.h>
#include <game/components/WorthComponent.h>
#include <game/events/LogEvent.h>
#include <sstream>

void ItemGatheringSystem::ProcessEntity(const ECS::IEntityPtr &entity, f64 dt) {
  auto bcc = entity->GetComponent<BoxColliderComponent>();
  auto wc = entity->GetComponent<WorthComponent>();
  for (const auto &collider : bcc->GetCollisions()) {
    if (collider->HasComponent<GathererComponent>()) {
      std::stringstream ss;
      ss << "Gather Coin of $" << wc->GetValue();
      GetEventSender()->Send<LogEvent>(ss.str());
      collider->GetComponent<GathererComponent>()->SaveCache(wc->GetValue());
      GetEntityManager()->Destroy(entity->GetID());
    }
  }
}
bool ItemGatheringSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<ItemComponent>() && entity->HasComponent<BoxColliderComponent>();
}
