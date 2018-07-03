/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#include <ECS/IEntity.h>
#include <game/components/RenderComponent.h>
#include <game/components/TransformComponent.h>
#include <ncurses.h>
#include <game/Consts.h>
#include "game/systems/RenderingSystem.h"

void RenderingSystem::PostUpdateInterval(double dt) {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            mvaddch(h, w, this->screen[w][h]);
            this->screen[w][h] = ' ';
        }
    }
    refresh();
}

void RenderingSystem::ProcessEntityInterval(ECS::IEntity *entity, double dt) {
    auto rc = entity->GetComponent<RenderComponent>();
    auto tc = entity->GetComponent<TransformComponent>();

    if (tc->position.x >= 0 && tc->position.y >= 0 && tc->position.x < width && tc->position.y < height) {
        this->screen[tc->position.x][tc->position.y] = rc->texture.symbol;
    }
}

const bool RenderingSystem::FamilyFilter(ECS::IEntity *entity) const {
    return entity->HasComponent<RenderComponent>() && entity->HasComponent<TransformComponent>();
}
RenderingSystem::RenderingSystem() : IntervalIteratingSystem(FPS) {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            this->screen[w][h] = ' ';
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
}
void RenderingSystem::OnDestroy() {
    endwin();
}
