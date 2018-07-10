/**
 * Created by Илья Сиганов on 16.06.2018.
 */

#ifndef ROGUELIKE_CONTROLSCOMPONENT_H
#define ROGUELIKE_CONTROLSCOMPONENT_H

#include <ECS/IComponent.h>
class ControlComponent : public ECS::IComponent {
 public:
  u32 up = 119;
  u32 down = 115;
  u32 left = 97;
  u32 right = 100;
};

#endif  // ROGUELIKE_CONTROLSCOMPONENT_H
