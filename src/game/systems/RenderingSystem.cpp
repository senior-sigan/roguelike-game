/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#include <ECS/IEntity.h>
#include <core/numerics.h>
#include <game/Consts.h>
#include <game/components/RenderComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/RenderingSystem.h>
#include <ncurses.h>
#include <game/components/RenderTargetComponent.h>

void RenderingSystem::PostUpdateInterval(f64 dt) {
  auto target = GetEntityManager()->Get(targetID);
  auto rtc = target->GetComponent<RenderTargetComponent>();

  for (u32 w = 0; w < rtc->size.x; w++) {
    for (u32 h = 0; h < rtc->size.y; h++) {
      auto tile = rtc->screen[w][h];
      attron(COLOR_PAIR(tile.color));
      mvaddch(h, w, tile.symbol);
      attroff(COLOR_PAIR(tile.color));
      rtc->screen[w][h].Clear();
    }
  }
  refresh();
}

void RenderingSystem::ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) {
  auto target = GetEntityManager()->Get(targetID);
  auto rc = entity->GetComponent<RenderComponent>();
  auto tc = entity->GetComponent<TransformComponent>();
  auto rtc = target->GetComponent<RenderTargetComponent>();

  if (tc->position.x >= 0 && tc->position.y >= 0 && unsigned_less(tc->position.x, rtc->size.x) &&
      unsigned_less(tc->position.y, rtc->size.y)) {
    rtc->screen[tc->position.x][tc->position.y] = Tile(rc->texture.symbol, rc->texture.color);
  }
}

bool RenderingSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<RenderComponent>() && entity->HasComponent<TransformComponent>();
}
void RenderingSystem::OnCreated() {
  initscr();
  raw();
  clear();
  noecho();
  cbreak();
  nodelay(stdscr, TRUE);
  keypad(stdscr, TRUE);
  curs_set(0);
  start_color();

  // TODO: this should be done based on colors we have in the components
  init_pair(0, COLOR_WHITE, COLOR_BLACK);
  init_pair(1, COLOR_YELLOW, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
}
void RenderingSystem::OnDestroy() {
  endwin();
}
RenderingSystem::RenderingSystem(const ECS::EntityID targetID)
    : IntervalIteratingSystem(FPS), targetID(targetID) {}
