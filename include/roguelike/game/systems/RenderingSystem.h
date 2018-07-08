/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_RENDERINGSYSTEM_H
#define ROGUELIKE_RENDERINGSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include <ECS/system/System.h>

struct Tile {
  char symbol;
  int color;

  void Clear() {
    symbol = ' ';
    color = 0;
  }

  explicit Tile(char symbol = ' ', int color = 0) : symbol(symbol), color(color) {}
};

class RenderingSystem : public ECS::IntervalIteratingSystem {
  // TODO: get somehow this sizes and be ready when it's changed. Or is it world size??? Not render page?
  static const uint width = 80;
  static const uint height = 24;
  Tile screen[width][height];

 public:
  explicit RenderingSystem();

  void PostUpdateInterval(double dt) override;
  void ProcessEntityInterval(const ECS::IEntityPtr &entity, double dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
  void OnCreated() override;
  void OnDestroy() override;
};

#endif  // ROGUELIKE_RENDERINGSYSTEM_H
