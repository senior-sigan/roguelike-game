/**
 * Created by Илья Сиганов on 24.06.2018.
 */

#ifndef ROGUELIKE_BEHAVIOURCOMPONENT_H
#define ROGUELIKE_BEHAVIOURCOMPONENT_H

#include <ECS/Component.h>
#include <ECS/IEngineControl.h>

/**
 * TODO: it should be a component that contains some behaviour inside
 */

class IBehaviour {
  friend class BehaviourSystem;
  ECS::IEngineControl &control; // TODO: set this control, so IBehaviour will be able to get other components.
 public:
  const ECS::IEngineControl &GetEngineControl() const {
      return control;
  }
  virtual void PreUpdate(double dt) {};
  virtual void Update(double dt) {};
  virtual void PostUpdate(double dt) {};
};

class BehaviourComponent : public ECS::Component<BehaviourComponent> {
  friend class BehaviourSystem;
 private:
  IBehaviour *behaviour;
 public:
  explicit BehaviourComponent(IBehaviour *behaviour) : behaviour(behaviour) {}
};

#endif //ROGUELIKE_BEHAVIOURCOMPONENT_H
