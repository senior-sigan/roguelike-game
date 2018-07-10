/**
 * Created by Илья Сиганов on 01.07.2018.
 */

#include <core/Geometry.h>

namespace Core {

bool Intersect(const Rectangle &r1, const Rectangle &r2) {
  return (r1.GetX1() < r2.GetX2()) && (r1.GetX2() > r2.GetX1()) && (r1.GetY1() < r2.GetY2()) &&
         (r1.GetY2() > r2.GetY1());
}

bool Contains(const Rectangle &r1, const Rectangle &r2) {
  return (r2.GetX1() >= r1.GetX1()) && (r2.GetY1() >= r1.GetY1()) && (r2.GetX2() <= r1.GetX2()) &&
         (r2.GetY2() <= r1.GetY2());
}

}