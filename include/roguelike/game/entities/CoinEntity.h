/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_COINENTITY_H
#define ROGUELIKE_COINENTITY_H

#include <ECS/Entity.h>
#include <game/components/TransformComponent.h>
#include <game/components/RenderComponent.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/ItemComponent.h>
#include <game/components/WorthComponent.h>
class CoinEntity : public ECS::Entity<CoinEntity> {
  Core::Vector2 pos;
  int value;
 public:
  explicit CoinEntity(const Core::Vector2 &pos, int value) : pos(pos), value(value) {}

  void OnCreated() override {
      AddComponent<TransformComponent>(pos);
      AddComponent<RenderComponent>(Texture1D('$'));
      AddComponent<BoxColliderComponent>(Core::Vector2::ONE, Core::Vector2::ZERO, true, false);
      AddComponent<ItemComponent>();
      AddComponent<WorthComponent>(value);
  }
};

#endif //ROGUELIKE_COINENTITY_H
