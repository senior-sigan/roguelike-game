/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_PLAYERENTITY_H
#define ROGUELIKE_PLAYERENTITY_H

#include <ECS/IEntity.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/ControlComponent.h>
#include <game/components/GathererComponent.h>
#include <game/components/MovementComponent.h>
#include <game/components/TileComponent.h>
#include <game/components/TransformComponent.h>

class PlayerEntity : public ECS::IEntity {
  Core::Vector2 pos;
  ECS::EntityID targetID;

 public:
  explicit PlayerEntity(const Core::Vector2 &pos, const ECS::EntityID &targetID) : pos(pos), targetID(targetID) {}

  void OnCreated() override {
    AddComponent<TransformComponent>(pos);
    AddComponent<TileComponent>(Texture1D('@', 2), targetID);
    AddComponent<ControlComponent>();
    AddComponent<MovementComponent>(Core::Vector2::ONE, Core::Vector2::ONE);
    AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, false, true);
    AddComponent<GathererComponent>();
  }
};

#endif  // ROGUELIKE_PLAYERENTITY_H
