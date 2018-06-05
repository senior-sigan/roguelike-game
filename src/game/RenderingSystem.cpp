/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#include <ECS/IEntity.h>
#include <game/RenderComponent.h>
#include <game/TransformComponent.h>
#include <ncurses.h>
#include "game/RenderingSystem.h"

void RenderingSystem::PostUpdate(double dt) {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            mvaddch(h, w, this->screen[w][h]);
        }
    }
    refresh();
}

void RenderingSystem::ProcessEntity(ECS::IEntity *entity, double dt) {
    auto rc = entity->GetComponent<RenderComponent>();
    auto tc = entity->GetComponent<TransformComponent>();

    this->screen[tc->position.x][tc->position.y] = rc->texture.symbol;
}
const bool RenderingSystem::FamilyFilter(ECS::IEntity *entity) const {
    return entity->HasComponent<RenderComponent>() && entity->HasComponent<TransformComponent>();
}
RenderingSystem::RenderingSystem() {
    for (int w = 0; w < width; w++) {
        for (int h = 0; h < height; h++) {
            this->screen[w][h] = '.';
        }
    }
}
