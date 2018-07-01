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

      engine->GetEntityManager()->CreateAndGet<PlayerEntity>();
      engine->GetEntityManager()->CreateAndGet<WallEntity>();

      return engine;
  }
};

#endif //ROGUELIKE_LEVEL_1_H
