/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#include <game/entities/CoinEntity.h>
#include <game/entities/ConsoleWindowEntity.h>
#include <game/entities/FillerEntity.h>
#include <game/entities/GameWindowEntity.h>
#include <game/entities/LogEntity.h>
#include <game/entities/PlayerEntity.h>
#include <game/entities/StatsWindowEntity.h>
#include <game/entities/WallEntity.h>
#include <game/stages/Stage_1.h>
#include <game/stages/lvl1.h>
#include <game/systems/CollisionSystem.h>
#include <game/systems/ControlSystem.h>
#include <game/systems/ExitSystem.h>
#include <game/systems/ItemGatheringSystem.h>
#include <game/systems/LogRenderingSystem.h>
#include <game/systems/LogSystem.h>
#include <game/systems/MovementSystem.h>
#include <game/systems/RenderingSystem.h>
#include <game/systems/TileRenderingSystem.h>
#include <random>

namespace {
// TODO: move it out from this scope. It should be IOC for random numbers.
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1, 6);

void createEntity(const ECS::EnginePtr &engine, u32 x, u32 y, char tile, const ECS::EntityID &targetID) {
  // TODO: create a configuration file that map tiles to entities and remove switch
  switch (tile) {
    case 0: {
      engine->GetEntityManager()->CreateAndGet<WallEntity>(Core::Vector2(x, y), targetID);
      break;
    }
    case 1: {
      engine->GetEntityManager()->CreateAndGet<CoinEntity>(Core::Vector2(x, y), distribution(generator), targetID);
      break;
    }
    default:
      break;
  }
}
}

ECS::EnginePtr Stage_1::load() {
  // TODO: By the way, we can load them from config files!
  auto engine = GetEngine();

  auto gameScreenId = engine->GetEntityManager()->Create<GameWindowEntity>(Core::Vector2::ZERO, Core::Vector2u(80, 24));
  auto consoleScreenId =
      engine->GetEntityManager()->Create<ConsoleWindowEntity>(Core::Vector2(0, 24), Core::Vector2u(80, 7));
  //  auto statsScreenId = engine->GetEntityManager()->Create<StatsWindowEntity>(
  //      Core::Vector2(80, 0), Core::Vector2u(20, 31));

  engine->GetSystemManager()->Create<InputSystem>();
  engine->GetSystemManager()->Create<RenderingSystem>();
  engine->GetSystemManager()->Create<TileRenderingSystem>();
  engine->GetSystemManager()->Create<ControlSystem>();
  engine->GetSystemManager()->Create<CollisionSystem>();
  engine->GetSystemManager()->Create<MovementSystem>();
  engine->GetSystemManager()->Create<ItemGatheringSystem>();
  engine->GetSystemManager()->Create<ExitSystem>();
  engine->GetSystemManager()->Create<LogSystem>();
  engine->GetSystemManager()->Create<LogRenderingSystem>();

  engine->GetEntityManager()->CreateAndGet<PlayerEntity>(Core::Vector2(1, 1), gameScreenId);

  for (u32 x = 0; x < lvl::width; x++) {
    for (u32 y = 0; y < lvl::height; y++) {
      createEntity(engine, x, y, lvl::data[y * lvl::width + x], gameScreenId);
    }
  }

  engine->GetEntityManager()->CreateAndGet<LogEntity>(consoleScreenId);

  //  engine->GetEntityManager()->CreateAndGet<FillerEntity>(Core::Vector2(0, 0), consoleScreenId);
  //  engine->GetEntityManager()->CreateAndGet<FillerEntity>(Core::Vector2(79, 6), consoleScreenId);
  //  engine->GetEntityManager()->CreateAndGet<FillerEntity>(Core::Vector2(0, 0), statsScreenId);
  //  engine->GetEntityManager()->CreateAndGet<FillerEntity>(Core::Vector2(19, 30), statsScreenId);

  return engine;
}
