/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <ncurses.h>
#include <game/systems/RenderingSystem.h>
#include <game/entities/PlayerEntity.h>
#include <game/systems/InputSystem.h>
#include <game/systems/ControlSystem.h>
#include <game/entities/WallEntity.h>
#include <game/Game.h>
#include <game/systems/CollisionSystem.h>
#include <game/systems/MovementSystem.h>

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
    engine->GetSystemManager()->CreateAndGet<CollisionSystem>();
    engine->GetSystemManager()->CreateAndGet<MovementSystem>();

    engine->GetEntityManager()->CreateAndGet<PlayerEntity>();
    engine->GetEntityManager()->CreateAndGet<WallEntity>();
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
