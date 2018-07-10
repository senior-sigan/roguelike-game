/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#ifndef ROGUELIKE_GATHERERCOMPONENT_H
#define ROGUELIKE_GATHERERCOMPONENT_H

#include <ECS/IComponent.h>
class GathererComponent : public ECS::IComponent {
  i32 cash = 0;

 public:
  i32 SaveCache(i32 value) {
    cash += value;
    return cash;
  }
};

#endif  // ROGUELIKE_GATHERERCOMPONENT_H
