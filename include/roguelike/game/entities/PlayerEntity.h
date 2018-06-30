/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_PLAYERENTITY_H
#define ROGUELIKE_PLAYERENTITY_H

#include <ECS/Entity.h>
#include "game/components/TransformComponent.h"
#include "game/components/RenderComponent.h"
#include "game/components/ControlComponent.h"
#include "game/components/BoxColliderComponent.h"

using namespace Core;
class PlayerEntity : public ECS::Entity<PlayerEntity> {
 public:
  void OnCreated() override {
      AddComponent<TransformComponent>(Vector2(1, 1));
      AddComponent<RenderComponent>(Texture1D('@'));
      AddComponent<ControlComponent>();
      AddComponent<BoxColliderComponent>(Vector2::ONE, Vector2::ZERO);
  }
};

#endif //ROGUELIKE_PLAYERENTITY_H
