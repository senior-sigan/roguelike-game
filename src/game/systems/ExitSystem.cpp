/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <game/systems/ExitSystem.h>
#include <game/buttons.h>

void ExitSystem::PreUpdateInterval(f64 dt) {
  if (Input::Instance().GetButtonDown(EXIT_KEY)) {
    GetEngineControl()->Stop();
  }
}
