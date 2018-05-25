/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_FAMILYTYPEID_H
#define ROGUELIKE_FAMILYTYPEID_H

#include "Platform.h"
namespace ECS {
class FamilyTypeID {
  static TypeID count;
 public:
  static const TypeID Get() {
      static const TypeID STATIC_TYPE_ID{count++};
      return count;
  }
};
}

#endif //ROGUELIKE_FAMILYTYPEID_H
