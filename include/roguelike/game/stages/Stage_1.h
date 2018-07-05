/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_LEVEL_1_H
#define ROGUELIKE_LEVEL_1_H

#include <ECS/Engine.h>
#include <game/stages/IStage.h>

class Stage_1 : public IStage {
  LOG_INIT("Stage_1");

 public:
  ECS::Engine* load() override;
};

#endif  // ROGUELIKE_LEVEL_1_H
