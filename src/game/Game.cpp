/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <game/Game.h>
#include <game/stages/Stage_1.h>
#include <game/systems/RenderingSystem.h>

void Game::SetupECS() {
  auto stage = new Stage_1();
  engine = stage->load();
}
void Game::Loop() {
  engine->Loop();
}
void Game::Teardown() {
  engine->OnDestroy();
}
void Game::Start() {
  SetupECS();
  Loop();
  Teardown();
}
