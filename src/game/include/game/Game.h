/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#ifndef ROGUELIKE_GAME_H
#define ROGUELIKE_GAME_H

#include <ECS/Engine.h>
/**
 * Main initializer of the game.
 */
class Game {
  ECS::Engine *engine = nullptr;

  void SetupGraphics();
  void SetupECS();
  void Loop();
  void Teardown();
 public:
  void Start();
};

#endif //ROGUELIKE_GAME_H
