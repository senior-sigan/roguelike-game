/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_ITEMSYSTEM_H
#define ROGUELIKE_ITEMSYSTEM_H

#include <ECS/system/IteratingSystem.h>

class ItemGatheringSystem : public ECS::IteratingSystem<ItemGatheringSystem> {
  LOG_INIT("ItemGatheringSystem");

 public:
  void ProcessEntity(const ECS::IEntityPtr &entity, double dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
};

#endif  // ROGUELIKE_ITEMSYSTEM_H
