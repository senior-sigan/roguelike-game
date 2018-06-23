/**
 * Created by Илья Сиганов on 23.06.2018.
 */

#include <game/InputSystem.h>

void InputSystem::PreUpdate(double dt) {
    int key = getch();
    currentKeys[key] = true;
}
void InputSystem::PostUpdateInterval(double dt) {
    // TODO: We may send events to subscribers.
    for (int i = 0; i < KEYS_SIZE; i++) {
        if (currentKeys[i]) {
            LOG_INFO(i);
        }
    }
    Clear();
}
void InputSystem::Clear() {
    for (bool &currentKey : currentKeys) {
        currentKey = false;
    }
}
bool InputSystem::GetButtonDown(unsigned int key) {
    if (key < KEYS_SIZE) {
        return currentKeys[key];
    } else {
        LOG_WARN("Button key must be between [0..255], but got " << key);
        return false;
    }
}
