/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#ifndef ROGUELIKE_WALLENTITY_H
#define ROGUELIKE_WALLENTITY_H

#include <ECS/Entity.h>
#include "game/components/TransformComponent.h"
#include "game/components/RenderComponent.h"
#include "game/components/ControlComponent.h"
#include "game/components/BoxColliderComponent.h"
class WallEntity : public ECS::Entity<WallEntity> {
  Core::Vector2 pos;
 public:
  explicit WallEntity(const Core::Vector2 &pos) : pos(pos) {}

  void OnCreated() override {
      AddComponent<TransformComponent>(pos);
      AddComponent<RenderComponent>(Texture1D('#'));
      AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, false, false);
  }
};

#endif //ROGUELIKE_WALLENTITY_H
