/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <ncurses.h>
#include <game/RenderingSystem.h>
#include <game/PlayerEntity.h>
#include <game/InputSystem.h>
#include <game/ControlSystem.h>
#include "game/Game.h"

void Game::SetupGraphics() {
    initscr();
    raw();
    clear();
    noecho();
    cbreak();
//    halfdelay(1);
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);
    curs_set(0);
}
void Game::SetupECS() {
    engine = new ECS::Engine();
    engine->GetSystemManager()->CreateAndGet<InputSystem>();
    engine->GetSystemManager()->CreateAndGet<RenderingSystem>();
    engine->GetSystemManager()->CreateAndGet<ControlSystem>();

    engine->GetEntityManager()->CreateAndGet<PlayerEntity>();
    // TODO: add all systems, components, entities
    // By the way, we can load them from config files!
}
void Game::Loop() {
    engine->Loop();
}
void Game::Teardown() {
    endwin();
}
void Game::Start() {
    SetupGraphics();
    SetupECS();
    Loop();
    Teardown();
}
