/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_RENDERINGSYSTEM_H
#define ROGUELIKE_RENDERINGSYSTEM_H

#include <ECS/system/IntervalIteratingSystem.h>
#include <ECS/system/System.h>

struct Tile {
  char symbol;
  i32 color;

  void Clear() {
    symbol = ' ';
    color = 0;
  }

  explicit Tile(char symbol = ' ', i32 color = 0) : symbol(symbol), color(color) {}
};

class RenderingSystem : public ECS::IntervalIteratingSystem {
  // TODO: get somehow this sizes and be ready when it's changed. Or is it world size??? Not render page?
  static const u32 width = 80;
  static const u32 height = 24;
  Tile screen[width][height];

 public:
  explicit RenderingSystem();

  void PostUpdateInterval(f64 dt) override;
  void ProcessEntityInterval(const ECS::IEntityPtr &entity, f64 dt) override;

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override;
  void OnCreated() override;
  void OnDestroy() override;
};

#endif  // ROGUELIKE_RENDERINGSYSTEM_H
