/**
 * Created by Илья Сиганов on 11.07.2018.
 */

#include <core/Geometry.h>
#include <core/Rectangle.h>
#include <core/numerics.h>
#include <game/Consts.h>
#include <game/components/TileComponent.h>
#include <game/components/RenderTargetComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/TileRenderingSystem.h>

void TileRenderingSystem::ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) {
  auto rc = entity->GetComponent<TileComponent>();
  auto tc = entity->GetComponent<TransformComponent>();
  auto target = GetEntityManager()->Get(rc->targetID);
  auto rtc = target->GetComponent<RenderTargetComponent>();

  if (tc->position.x >= 0 && tc->position.y >= 0 && Core::UnsignedLess(tc->position.x, rtc->size.x) &&
      Core::UnsignedLess(tc->position.y, rtc->size.y)) {
    rtc->screen[tc->position.x][tc->position.y] = Tile(rc->texture.symbol, rc->texture.color);
  }
}

bool TileRenderingSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<TileComponent>() && entity->HasComponent<TransformComponent>();
}
TileRenderingSystem::TileRenderingSystem() : IntervalIteratingSystem(FPS) {}
