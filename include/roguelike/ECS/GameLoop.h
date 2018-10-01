/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#ifndef ROGUELIKE_GAMELOOP_H
#define ROGUELIKE_GAMELOOP_H

#include <core/types.h>
namespace ECS {
class GameLoop {
  bool running = true;

 protected:
  virtual void Update(f64 deltaTime) = 0;

 public:
  void Loop();
  void Stop();
  virtual ~GameLoop() = default;
};
}
#endif  // ROGUELIKE_GAMELOOP_H
