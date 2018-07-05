/**
 * Created by Илья Сиганов on 05.07.2018.
 */

#ifndef ROGUELIKE_NUMERICS_H
#define ROGUELIKE_NUMERICS_H

bool unsigned_less(int a, unsigned int b) {
  return a < 0 || static_cast<unsigned int>(a) < b;
}

#endif  // ROGUELIKE_NUMERICS_H
