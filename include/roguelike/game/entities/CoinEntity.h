/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_COINENTITY_H
#define ROGUELIKE_COINENTITY_H

#include <ECS/IEntity.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/ItemComponent.h>
#include <game/components/TileComponent.h>
#include <game/components/TransformComponent.h>
#include <game/components/WorthComponent.h>
class CoinEntity : public ECS::IEntity {
  Core::Vector2 pos;
  i32 value;
  ECS::EntityID targetID;

 public:
  explicit CoinEntity(const Core::Vector2 &pos, i32 value, const ECS::EntityID &targetID)
      : pos(pos), value(value), targetID(targetID) {}

  void OnCreated() override {
    AddComponent<TransformComponent>(pos);
    AddComponent<TileComponent>(Texture1D('$', 1), targetID);
    AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, true, false);
    AddComponent<ItemComponent>();
    AddComponent<WorthComponent>(value);
  }
};

#endif  // ROGUELIKE_COINENTITY_H
