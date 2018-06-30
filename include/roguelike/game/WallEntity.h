/**
 * Created by Илья Сиганов on 30.06.2018.
 */

#ifndef ROGUELIKE_WALLENTITY_H
#define ROGUELIKE_WALLENTITY_H

#include <ECS/Entity.h>
#include "TransformComponent.h"
#include "RenderComponent.h"
#include "ControlComponent.h"
#include "BoxColliderComponent.h"
class WallEntity : public ECS::Entity<WallEntity> {
 public:
  void OnCreated() override {
      AddComponent<TransformComponent>(Vector2(5, 2));
      AddComponent<RenderComponent>(Texture1D('#'));
      AddComponent<BoxColliderComponent>(Vector2::ONE, Vector2::ZERO);
  }
};

#endif //ROGUELIKE_WALLENTITY_H
