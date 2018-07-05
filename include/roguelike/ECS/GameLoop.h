/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#ifndef ROGUELIKE_GAMELOOP_H
#define ROGUELIKE_GAMELOOP_H

namespace ECS {
class GameLoop {
  bool running = true;

 protected:
  virtual void Update(double deltaTime) = 0;

 public:
  void Loop();
  void Stop();
};
}
#endif  // ROGUELIKE_GAMELOOP_H
