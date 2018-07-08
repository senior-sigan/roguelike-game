/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <game/Game.h>
#include <game/stages/Stage_1.h>

void Game::SetupECS() {
  auto stage = std::make_shared<Stage_1>();
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
