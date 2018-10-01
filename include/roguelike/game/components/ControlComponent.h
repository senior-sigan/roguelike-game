/**
 * Created by Илья Сиганов on 16.06.2018.
 */

#ifndef ROGUELIKE_CONTROLSCOMPONENT_H
#define ROGUELIKE_CONTROLSCOMPONENT_H

#include <ECS/IComponent.h>
#include <game/buttons.h>
#include <core/types.h>

class ControlComponent : public ECS::IComponent {
 public:
  // TODO: actually we would better to have different implementations or config file....
  u32 up = UP_KEY;
  u32 down = DOWN_KEY;
  u32 left = LEFT_KEY;
  u32 right = RIGHT_KEY;
};

#endif  // ROGUELIKE_CONTROLSCOMPONENT_H
