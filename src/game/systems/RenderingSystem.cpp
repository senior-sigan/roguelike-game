/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#include <ECS/IEntity.h>
#include <core/numerics.h>
#include <game/Consts.h>
#include <game/components/TileComponent.h>
#include <game/components/RenderTargetComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/RenderingSystem.h>
#include <ncurses.h>

void RenderingSystem::PostProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) {
  auto rtc = entity->GetComponent<RenderTargetComponent>();
  auto tc = entity->GetComponent<TransformComponent>();
  for (u32 w = 0; w < rtc->size.x; w++) {
    for (u32 h = 0; h < rtc->size.y; h++) {
      auto tile = rtc->screen[w][h];
      attron(COLOR_PAIR(tile.color));
      mvaddch(h + tc->position.y, w + tc->position.x, tile.symbol);
      attroff(COLOR_PAIR(tile.color));
      rtc->screen[w][h].Clear();
    }
  }
  refresh();
}

bool RenderingSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<RenderTargetComponent>() && entity->HasComponent<TransformComponent>();
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
  init_pair(3, COLOR_BLACK, COLOR_WHITE);
}
void RenderingSystem::OnDestroy() {
  endwin();
}
RenderingSystem::RenderingSystem() : IntervalIteratingSystem(FPS) {}
