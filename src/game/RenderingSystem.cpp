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

void RenderingSystem::PostUpdateInterval(double dt) {
  for (uint w = 0; w < width; w++) {
    for (uint h = 0; h < height; h++) {
      auto tile = this->screen[w][h];
      attron(COLOR_PAIR(tile.color));
      mvaddch(h, w, tile.symbol);
      attroff(COLOR_PAIR(tile.color));
      this->screen[w][h].Clear();
    }
  }
  refresh();
}

void RenderingSystem::ProcessEntityInterval(ECS::IEntity* entity, double dt) {
  auto rc = entity->GetComponent<RenderComponent>();
  auto tc = entity->GetComponent<TransformComponent>();

  if (tc->position.x >= 0 && tc->position.y >= 0 && unsigned_less(tc->position.x, width) &&
      unsigned_less(tc->position.y, height)) {
    this->screen[tc->position.x][tc->position.y] = Tile(rc->texture.symbol, rc->texture.color);
  }
}

bool RenderingSystem::FamilyFilter(ECS::IEntity* entity) const {
  return entity->HasComponent<RenderComponent>() && entity->HasComponent<TransformComponent>();
}
RenderingSystem::RenderingSystem() : IntervalIteratingSystem(FPS) {
  for (uint w = 0; w < width; w++) {
    for (uint h = 0; h < height; h++) {
      this->screen[w][h] = Tile();
    }
  }
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
