/**
 * Created by Илья Сиганов on 02.06.2018.
 */

#include "GameLoop.h"
#include <chrono>

namespace ECS {
void GameLoop::Loop() {
    auto previous = std::chrono::system_clock::now();
    while (running) {
        auto current = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed = current - previous;
        previous = current;
        Update(elapsed.count());
    }
}
void GameLoop::Stop() {
    running = false;
}
}