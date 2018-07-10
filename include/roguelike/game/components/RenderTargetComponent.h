/**
 * Created by Илья Сиганов on 10.07.2018.
 */

#ifndef ROGUELIKE_RENDERTEXTURE_H
#define ROGUELIKE_RENDERTEXTURE_H

#include <ECS/IComponent.h>
#include <core/types.h>
#include <core/vector2.h>
class RenderTargetComponent : public ECS::IComponent {
 public:
  Core::Vector2 size;
};

#endif  // ROGUELIKE_RENDERTEXTURE_H
