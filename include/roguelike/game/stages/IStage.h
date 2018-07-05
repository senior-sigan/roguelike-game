/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_ISTAGE_H
#define ROGUELIKE_ISTAGE_H

#include <ECS/Engine.h>
class IStage {
  ECS::Engine *const engine;

 public:
  IStage() : engine(new ECS::Engine()) {}
  virtual ~IStage() {
    delete engine;
  }
  ECS::Engine *GetEngine() const {
    return engine;
  }

  virtual ECS::Engine *load() = 0;
};

#endif  // ROGUELIKE_ISTAGE_H
