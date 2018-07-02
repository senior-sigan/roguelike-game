/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_ITEMSYSTEM_H
#define ROGUELIKE_ITEMSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include <game/components/ItemComponent.h>

class ItemGatheringSystem : public ECS::IteratingSystem<ItemGatheringSystem> {
  LOG_INIT("ItemGatheringSystem");
 public:
  void ProcessEntity(ECS::IEntity *entity, double dt) override {
      auto bcc = entity->GetComponent<BoxColliderComponent>();
      for (auto collider: bcc->GetCollisions()) {
//          if (collider is player) {
//              LOG_INFO("Collide Player");
//              TODO: remove entity and add coins to player
//          }
      }
  }

  const bool FamilyFilter(const ECS::IEntity *entity) const override {
      return entity->HasComponent<ItemComponent>() && entity->HasComponent<BoxColliderComponent>();
  }
};

#endif //ROGUELIKE_ITEMSYSTEM_H
