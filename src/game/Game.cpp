/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <ncurses.h>
#include <game/systems/RenderingSystem.h>
#include <game/Game.h>
#include <game/stages/Stage_1.h>

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
    auto stage = new Stage_1();
    engine = stage->load();
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
