/**
 * Created by Илья Сиганов on 10.07.2018.
 */

#ifndef ROGUELIKE_FILLERENTITY_H
#define ROGUELIKE_FILLERENTITY_H

#include <ECS/IEntity.h>
#include <game/components/BoxColliderComponent.h>
#include <game/components/ControlComponent.h>
#include <game/components/RenderComponent.h>
#include <game/components/TransformComponent.h>
class FillerEntity : public ECS::IEntity {
  Core::Vector2 pos;
  ECS::EntityID targetID;

 public:
  explicit FillerEntity(const Core::Vector2 &pos, const ECS::EntityID &targetID) : pos(pos), targetID(targetID) {}

  void OnCreated() override {
    AddComponent<TransformComponent>(pos);
    AddComponent<RenderComponent>(Texture1D(' ', 3), targetID);
  }
};

#endif  // ROGUELIKE_FILLERENTITY_H
