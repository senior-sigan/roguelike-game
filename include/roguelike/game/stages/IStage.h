/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_ISTAGE_H
#define ROGUELIKE_ISTAGE_H

#include <ECS/Engine.h>
class IStage {
  ECS::EnginePtr engine;

 public:
  IStage() : engine(std::make_shared<ECS::Engine>()) {}

  ECS::EnginePtr GetEngine() const {
    return engine;
  }

  virtual ECS::EnginePtr load() = 0;
  virtual ~IStage() = default;
};

#endif  // ROGUELIKE_ISTAGE_H
