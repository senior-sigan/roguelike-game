/**
 * Created by Илья Сиганов on 02.07.2018.
 */

#ifndef ROGUELIKE_WORTHCOMPONENT_H
#define ROGUELIKE_WORTHCOMPONENT_H

#include <ECS/IComponent.h>
class WorthComponent : public ECS::IComponent {
  i32 value;

 public:
  explicit WorthComponent(i32 value) : value(value) {}

  i32 GetValue() const {
    return value;
  }
};

#endif  // ROGUELIKE_WORTHCOMPONENT_H
