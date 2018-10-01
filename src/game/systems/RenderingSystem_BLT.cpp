/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifdef BEARLIBTERMINAL

#include <ECS/IEntity.h>
#include <core/numerics.h>
#include <game/Consts.h>
#include <game/components/TileComponent.h>
#include <game/components/RenderTargetComponent.h>
#include <game/components/TransformComponent.h>
#include <game/systems/RenderingSystem.h>
#include <BearLibTerminal.h>



void RenderingSystem::PostProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) {
  auto rtc = entity->GetComponent<RenderTargetComponent>();
  auto tc = entity->GetComponent<TransformComponent>();
  for (u32 w = 0; w < rtc->size.x; w++) {
    for (u32 h = 0; h < rtc->size.y; h++) {
      auto tile = rtc->screen[w][h];

      // TODO: yes I know it's switch. I'll move it out, make a config for this
      switch (tile.color) {
        case 0:
          terminal_color(color_from_name("white"));
          break;
        case 1:
          terminal_color(color_from_name("yellow"));
          break;
        case 2:
          terminal_color(color_from_name("green"));
          break;
        case 3:
          terminal_color(color_from_name("black"));
          break;
        default:
          terminal_color(color_from_name("white"));
          break;
      }
      switch (tile.color) {
        case 0:
          terminal_bkcolor(color_from_name("black"));
          break;
        case 1:
          terminal_bkcolor(color_from_name("black"));
          break;
        case 2:
          terminal_bkcolor(color_from_name("black"));
          break;
        case 3:
          terminal_bkcolor(color_from_name("white"));
          break;
        default:
          terminal_bkcolor(color_from_name("black"));
          break;
      }
      terminal_put(w + tc->position.x, h + tc->position.y, tile.symbol);

      rtc->screen[w][h].Clear();
    }
  }
  terminal_refresh();
}

bool RenderingSystem::FamilyFilter(const ECS::IEntityPtr &entity) const {
  return entity->HasComponent<RenderTargetComponent>() && entity->HasComponent<TransformComponent>();
}
void RenderingSystem::OnCreated() {
  terminal_open();
  terminal_refresh();
  terminal_set("window: size=90x31, cellsize=auto, title='Roguelike'; font: default");
  terminal_color("white");
}
void RenderingSystem::OnDestroy() {
  terminal_close();
}
RenderingSystem::RenderingSystem() : IntervalIteratingSystem(FPS) {}

#endif