/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#ifndef ROGUELIKE_LINE_H
#define ROGUELIKE_LINE_H

#include <core/vector2.h>

namespace Core {

class Line {
  Vector2 a;
  Vector2 b;

 public:
  Line(const Vector2 &a, const Vector2 &b);
  double GetLength() const;
};

}

#endif  // ROGUELIKE_LINE_H
