/**
 * Created by Илья Сиганов on 11.07.2018.
 */

#include <core/numerics.h>
namespace Core {
bool UnsignedLess(i32 a, u32 b) {
  return a < 0 || static_cast<u32>(a) < b;
}
}
