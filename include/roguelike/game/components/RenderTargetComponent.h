/**
 * Created by Илья Сиганов on 10.07.2018.
 */

#ifndef ROGUELIKE_RENDERTEXTURE_H
#define ROGUELIKE_RENDERTEXTURE_H

#include <ECS/IComponent.h>
#include <core/types.h>
#include <core/vector2.h>

struct Tile {
  char symbol;
  i32 color;

  void Clear() {
    symbol = ' ';
    color = 0;
  }

  explicit Tile(char symbol = ' ', i32 color = 0) : symbol(symbol), color(color) {}
};

class RenderTargetComponent : public ECS::IComponent {
 public:
  Tile **screen;
  Core::Vector2u size;

  explicit RenderTargetComponent(const Core::Vector2u &size) : size(size) {
    screen = new Tile*[size.x];
    for (u32 x = 0; x < size.x; x++) {
      screen[x] = new Tile[size.y];
    }
  }
  virtual ~RenderTargetComponent() {
    for (u32 x = 0; x < size.x; x++) {
      delete [] screen[x];
    }
    delete [] screen;
  }
};

#endif  // ROGUELIKE_RENDERTEXTURE_H
