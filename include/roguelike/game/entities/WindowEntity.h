/**
 * Created by Илья Сиганов on 10.07.2018.
 */

#ifndef ROGUELIKE_WINDOWENTITY_H
#define ROGUELIKE_WINDOWENTITY_H

#include <ECS/IEntity.h>
#include <game/components/RenderTargetComponent.h>
#include <game/components/TransformComponent.h>
class WindowEntity : public ECS::IEntity {
  Core::Vector2 pos;
  Core::Vector2 size;

 public:
  void OnCreated() override {
    AddComponent<RenderTargetComponent>(size);
    AddComponent<TransformComponent>(pos);
  }
};

#endif  // ROGUELIKE_WINDOWENTITY_H
