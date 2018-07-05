/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include <ECS/GameLoop.h>
#include <chrono>
#include <thread>

namespace ECS {
void GameLoop::Loop() {
  auto previous = std::chrono::system_clock::now();
  while (running) {
    auto current = std::chrono::system_clock::now();
    std::chrono::duration<double, std::ratio<1>> elapsed = current - previous;
    previous = current;
    Update(elapsed.count());
//    std::this_thread::sleep_for(std::chrono::milliseconds(30));
  }
}
void GameLoop::Stop() {
  running = false;
}
}