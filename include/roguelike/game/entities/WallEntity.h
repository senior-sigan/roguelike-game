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
  Vector2 pos;
 public:
  explicit WallEntity(const Vector2 &pos) : pos(pos) {}

  void OnCreated() override {
      AddComponent<TransformComponent>(pos);
      AddComponent<RenderComponent>(Texture1D('#'));
      AddComponent<BoxColliderComponent>(Vector2::ONE, Vector2::ZERO);
  }
};

#endif //ROGUELIKE_WALLENTITY_H
