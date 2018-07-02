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
#include "lvl1.h"
class Stage_1 : public IStage {
  LOG_INIT("Stage_1");
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

      for (int x = 0; x < lvl::width; x++) {
          for (int y = 0; y < lvl::height; y++) {
              createEntity(engine, x, y, lvl::data[y*lvl::width + x]);
          }
      }

      return engine;
  }

  void createEntity(ECS::Engine *const engine, int x, int y, char tile) {
      // TODO: create a configuration file that map tiles to entities and remove switch
      switch (tile) {
          case 0: {
              engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(x, y));
              break;
          }
          case 1: {
              engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(x, y), 1);
              break;
          }
          default:break;
      }
  }
};

#endif //ROGUELIKE_LEVEL_1_H
