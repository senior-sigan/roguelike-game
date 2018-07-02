/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_WORTHCOMPONENT_H
#define ROGUELIKE_WORTHCOMPONENT_H

#include <ECS/Component.h>
class WorthComponent : public ECS::Component<WorthComponent> {
  int value;
 public:
  explicit WorthComponent(int value) : value(value) {}

  int GetValue() const {
      return value;
  }
};

#endif //ROGUELIKE_WORTHCOMPONENT_H
