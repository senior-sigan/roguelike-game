/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#ifndef ROGUELIKE_WALLENTITY_H
#define ROGUELIKE_WALLENTITY_H

#include <ECS/IEntity.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/ControlComponent.h>
#include <game/components/TileComponent.h>
#include <game/components/TransformComponent.h>
class WallEntity : public ECS::IEntity {
  Core::Vector2 pos;
  ECS::EntityID targetID;

 public:
  explicit WallEntity(const Core::Vector2 &pos, const ECS::EntityID &targetID) : pos(pos), targetID(targetID) {}

  void OnCreated() override {
    AddComponent<TransformComponent>(pos);
    AddComponent<TileComponent>(Texture1D('#'), targetID);
    AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, false, false);
  }
};

#endif  // ROGUELIKE_WALLENTITY_H
