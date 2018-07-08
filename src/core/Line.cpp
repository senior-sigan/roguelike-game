/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#include <core/Line.h>
#include <cmath>

Core::Line::Line(const Core::Vector2 &a, const Core::Vector2 &b) : a(a), b(b) {}

double Core::Line::GetLength() const {
  return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
}
