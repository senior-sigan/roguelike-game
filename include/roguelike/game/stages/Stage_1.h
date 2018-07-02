/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_LEVEL_1_H
#define ROGUELIKE_LEVEL_1_H

#include <ECS/Engine.h>
#include <game/systems/InputSystem.h>
#include <game/systems/RenderingSystem.h>
#include <game/systems/ControlSystem.h>
#include <game/systems/CollisionSystem.h>
#include <game/systems/MovementSystem.h>
#include <game/entities/PlayerEntity.h>
#include <game/entities/WallEntity.h>
#include <game/systems/ItemGatheringSystem.h>
#include <game/entities/CoinEntity.h>
#include "IStage.h"
class Stage_1 : public IStage {
 public:
  ECS::Engine *const load() override {
      // TODO: By the way, we can load them from config files!
      auto engine = GetEngine();

      engine->GetSystemManager()->CreateAndGet<InputSystem>();
      engine->GetSystemManager()->CreateAndGet<RenderingSystem>();
      engine->GetSystemManager()->CreateAndGet<ControlSystem>();
      engine->GetSystemManager()->CreateAndGet<CollisionSystem>();
      engine->GetSystemManager()->CreateAndGet<MovementSystem>();
      engine->GetSystemManager()->CreateAndGet<ItemGatheringSystem>();

      engine->GetEntityManager()->CreateAndGet<PlayerEntity>(Core::Vector2(1, 1));
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(5, 2));
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(5, 3));
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(5, 4));
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(5, 6));
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(5, 7));

      engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(3,3), 1);
      engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(6,3), 1);
      engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(1,8), 1);
      engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(4,1), 1);

      return engine;
  }
};

#endif //ROGUELIKE_LEVEL_1_H
