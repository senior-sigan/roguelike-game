/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/systems/InputSystem.h>
#include <ncurses.h>

void InputSystem::PreUpdate(double dt) {
  int key = getch();
  Input::Instance().currentKeys[key] = true;
}
void InputSystem::PostUpdateInterval(double dt) {
  // TODO: We may send events to subscribers.
  Input::Instance().Clear();
}
