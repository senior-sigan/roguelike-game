/**
 * Created by Илья Сиганов on 10.07.2018.
 */

#include <core/vector2.h>

namespace Core {
Vector2 Vector2::UP = Vector2(0, -1);
Vector2 Vector2::DOWN = Vector2(0, 1);
Vector2 Vector2::RIGHT = Vector2(1, 0);
Vector2 Vector2::LEFT = Vector2(-1, 0);
Vector2 Vector2::ZERO = Vector2(0, 0);
Vector2 Vector2::ONE = Vector2(1, 1);

Vector2u Vector2u::ZERO = Vector2u(0, 0);
Vector2u Vector2u::ONE = Vector2u(1, 1);
}