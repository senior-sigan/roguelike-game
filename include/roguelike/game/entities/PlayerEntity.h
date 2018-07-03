/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_PLAYERENTITY_H
#define ROGUELIKE_PLAYERENTITY_H

#include <ECS/Entity.h>
#include <game/components/MovementComponent.h>
#include <game/components/GathererComponent.h>
#include "game/components/TransformComponent.h"
#include "game/components/RenderComponent.h"
#include "game/components/ControlComponent.h"
#include "game/components/BoxColliderComponent.h"

class PlayerEntity : public ECS::Entity<PlayerEntity> {
  Core::Vector2 pos;
 public:
  explicit PlayerEntity(const Core::Vector2 &pos) : pos(pos) {}

  void OnCreated() override {
      AddComponent<TransformComponent>(pos);
      AddComponent<RenderComponent>(Texture1D('@'));
      AddComponent<ControlComponent>();
      AddComponent<MovementComponent>(Core::Vector2::ONE, Core::Vector2::ONE);
      AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, false, true);
      AddComponent<GathererComponent>();
  }
};

#endif //ROGUELIKE_PLAYERENTITY_H
