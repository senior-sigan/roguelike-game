/**
 * Created by Илья Сиганов on 16.06.2018.
 */

#ifndef ROGUELIKE_CONTROLSCOMPONENT_H
#define ROGUELIKE_CONTROLSCOMPONENT_H

#include <ECS/IComponent.h>
class ControlComponent : public ECS::IComponent {
 public:
  unsigned int up = 119;
  unsigned int down = 115;
  unsigned int left = 97;
  unsigned int right = 100;
};

#endif  // ROGUELIKE_CONTROLSCOMPONENT_H
