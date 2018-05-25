/**
 * Created by Илья Сиганов on 25.05.2018.
 *
 * Used to define some types aliases, platform specific code.
 */

#ifndef ROGUELIKE_PLATFORM_H
#define ROGUELIKE_PLATFORM_H

#include <cstdio>
#include <gmpxx.h>
namespace ECS {

using ObjectID = size_t;
using TypeID = size_t;

static const ObjectID INVALID_OBJECT_ID = std::numeric_limits<ObjectID>::max();
static const TypeID INVALID_TYPE_ID = std::numeric_limits<TypeID>::max();

}

#endif //ROGUELIKE_PLATFORM_H
