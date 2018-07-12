/**
 * Created by Илья Сиганов on 13.07.2018.
 */

#ifndef ROGUELIKE_LOGENTITY_H
#define ROGUELIKE_LOGENTITY_H

#include <ECS/IEntity.h>
#include <game/components/LogComponent.h>
#include <game/components/TransformComponent.h>

class LogEntity : public ECS::IEntity {
  ECS::EntityID targetID;

 public:
  explicit LogEntity(const ECS::EntityID &targetID) : targetID(targetID) {}

  void OnCreated() override {
    AddComponent<TransformComponent>(Core::Vector2::ZERO);
    AddComponent<LogComponent>(7, targetID);
  }
};

#endif  // ROGUELIKE_LOGENTITY_H
