/**
 * Created by Илья Сиганов on 12.07.2018.
 */

#ifndef ROGUELIKE_LOGRENDERINGSYSTEM_H
#define ROGUELIKE_LOGRENDERINGSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include <game/Consts.h>
#include <game/components/LogComponent.h>
#include <game/components/RenderTargetComponent.h>
#include <game/components/TransformComponent.h>
#include <cstdio>
#include <string>

class LogRenderingSystem : public ECS::IntervalIteratingSystem {
 public:
  explicit LogRenderingSystem() : IntervalIteratingSystem(FPS) {}

  void ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) override {
    auto lc = entity->GetComponent<LogComponent>();
    auto target = GetEntityManager()->Get(lc->targetID);
    auto rtc = target->GetComponent<RenderTargetComponent>();

    u32 y = 0;
    for (const std::string &text : lc->Get()) {
      for (size_t x = 0; x < text.size(); x++) {
        rtc->screen[x][y] = Tile(text[x]);
      }
      y++;
    }
  }

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override {
    return entity->HasComponent<LogComponent>() && entity->HasComponent<TransformComponent>();
  }
};

#endif  // ROGUELIKE_LOGRENDERINGSYSTEM_H
