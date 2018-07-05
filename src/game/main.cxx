/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include "game/Game.h"

int main() {
  LOG_CONFIGURE();
  auto game = std::make_unique<Game>();
  game->Start();
}