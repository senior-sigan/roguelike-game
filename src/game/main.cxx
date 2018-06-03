/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include "Game.h"

int main() {
    LOG_CONFIGURE();
    auto game = new Game();
    game->Start();
}

