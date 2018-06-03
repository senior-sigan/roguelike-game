/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_RENDERINGSYSTEM_H
#define ROGUELIKE_RENDERINGSYSTEM_H

#include <ECS/System.h>
class RenderingSystem: public ECS::System<RenderingSystem> {
  //TODO: get somehow this sizes and be ready when it's changed. Or is it world size??? Not render page?
  static const unsigned int width = 80;
  static const unsigned int height = 24;
  char screen[width][height]{};
 public:
  RenderingSystem();
  void PreUpdate(ECS::IEntity *entity, double dt) override;
  const bool FamilyFilter(ECS::IEntity *entity) const override;
  void Update(ECS::IEntity *entity, double dt) override;
};

#endif //ROGUELIKE_RENDERINGSYSTEM_H
