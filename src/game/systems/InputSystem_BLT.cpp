/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#ifdef BEARLIBTERMINAL

#include <game/systems/InputSystem.h>
#include <BearLibTerminal.h>

void InputSystem::PreUpdate(f64 dt) {
  if (terminal_has_input()) {
    i32 key = terminal_read();  // TODO: here is some bug so keys, for example exit, isn't read.
    LOG_INFO("key: " << key);
    Input::Instance().currentKeys[key] = true;
  }
}
void InputSystem::PostUpdateInterval(f64 dt) {
  // TODO: We may send events to subscribers.
  Input::Instance().Clear();
}

bool Input::GetButtonDown(u32 key) {
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

#endif