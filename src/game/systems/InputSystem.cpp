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

bool Input::GetButtonDown(unsigned int key) {
  if (key < KEYS_SIZE) {
    return currentKeys[key];
  } else {
    return false;
  }
}
void Input::Clear() {
  for (bool &currentKey : currentKeys) {
    currentKey = false;
  }
}