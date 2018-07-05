/**
 * Created by Илья Сиганов on 03.07.2018.
 */

#ifndef ROGUELIKE_GATHERERCOMPONENT_H
#define ROGUELIKE_GATHERERCOMPONENT_H

#include <ECS/Component.h>
class GathererComponent : public ECS::Component<GathererComponent> {
  int cash = 0;

 public:
  int SaveCache(int value) {
    cash += value;
    return cash;
  }
};

#endif  // ROGUELIKE_GATHERERCOMPONENT_H
