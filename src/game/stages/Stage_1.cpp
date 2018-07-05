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
#include <game/systems/InputSystem.h>
#include <game/systems/ItemGatheringSystem.h>
#include <game/systems/MovementSystem.h>
#include <game/systems/RenderingSystem.h>

namespace {
void createEntity(ECS::Engine* const engine, int x, int y, char tile) {
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
    default:
      break;
  }
}
}

ECS::Engine* Stage_1::load() {
  // TODO: By the way, we can load them from config files!
  auto engine = GetEngine();

  engine->GetSystemManager()->CreateAndGet<InputSystem>();
  engine->GetSystemManager()->CreateAndGet<RenderingSystem>();
  engine->GetSystemManager()->CreateAndGet<ControlSystem>();
  engine->GetSystemManager()->CreateAndGet<CollisionSystem>();
  engine->GetSystemManager()->CreateAndGet<MovementSystem>();
  engine->GetSystemManager()->CreateAndGet<ItemGatheringSystem>();
  engine->GetSystemManager()->CreateAndGet<ExitSystem>();

  engine->GetEntityManager()->CreateAndGet<PlayerEntity>(Core::Vector2(1, 1));

  for (uint x = 0; x < lvl::width; x++) {
    for (uint y = 0; y < lvl::height; y++) {
      createEntity(engine, x, y, lvl::data[y * lvl::width + x]);
    }
  }

  return engine;
}
