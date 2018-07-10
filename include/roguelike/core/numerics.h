/**
 * Created by Илья Сиганов on 05.07.2018.
 */

#ifndef ROGUELIKE_NUMERICS_H
#define ROGUELIKE_NUMERICS_H

#include "core/types.h"
bool unsigned_less(i32 a, u32 b) {
  return a < 0 || static_cast<u32>(a) < b;
}

#endif  // ROGUELIKE_NUMERICS_H
