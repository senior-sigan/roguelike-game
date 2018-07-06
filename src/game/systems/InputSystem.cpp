/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/systems/InputSystem.h>
#include <ncurses.h>

void InputSystem::PreUpdate(double dt) {
  int key = getch();
  currentKeys[key] = true;
  LOG_INFO("current time " << GetCurrentTime() << " " << dt);
}
void InputSystem::PostUpdateInterval(double dt) {
  LOG_INFO("long upd " << dt);
  // TODO: We may send events to subscribers.
  Clear();
}
void InputSystem::Clear() {
  for (bool& currentKey : currentKeys) {
    currentKey = false;
  }
}
bool InputSystem::GetButtonDown(uint key) {
  if (key < KEYS_SIZE) {
    return currentKeys[key];
  } else {
    return false;
  }
}
