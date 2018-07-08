/**
 * Created by Илья Сиганов on 08.07.2018.
 */

#include <game/systems/ExitSystem.h>

void ExitSystem::PreUpdateInterval(double dt) {
  if (Input::Instance().GetButtonDown('q')) {
    GetEngineControl()->Stop();
  }
}
