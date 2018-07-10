/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#include <game/entities/CoinEntity.h>
#include <game/entities/PlayerEntity.h>
#include <game/entities/WallEntity.h>
#include <game/stages/Stage_1.h>
#include <game/stages/lvl1.h>
#include <game/systems/CollisionSystem.h>
#include <game/systems/ControlSystem.h>
#include <game/systems/ExitSystem.h>
#include <game/systems/ItemGatheringSystem.h>
#include <game/systems/MovementSystem.h>
#include <game/systems/RenderingSystem.h>

namespace {
void createEntity(const ECS::EnginePtr &engine, u32 x, u32 y, char tile) {
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
}

ECS::EnginePtr Stage_1::load() {
  // TODO: By the way, we can load them from config files!
  auto engine = GetEngine();

  engine->GetSystemManager()->Create<InputSystem>();
  engine->GetSystemManager()->Create<RenderingSystem>();
  engine->GetSystemManager()->Create<ControlSystem>();
  engine->GetSystemManager()->Create<CollisionSystem>();
  engine->GetSystemManager()->Create<MovementSystem>();
  engine->GetSystemManager()->Create<ItemGatheringSystem>();
  engine->GetSystemManager()->Create<ExitSystem>();

  engine->GetEntityManager()->CreateAndGet<PlayerEntity>(Core::Vector2(1, 1));

  for (u32 x = 0; x < lvl::width; x++) {
    for (u32 y = 0; y < lvl::height; y++) {
      createEntity(engine, x, y, lvl::data[y * lvl::width + x]);
    }
  }

  return engine;
}
