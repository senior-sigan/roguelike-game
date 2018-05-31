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

using EventTypeID = TypeID;

using EventDelegateID = ObjectID;
using EventDelegateTypeID = TypeID;

using ComponentTypeID = TypeID;
using ComponentID = ObjectID;

using EntityTypeID = TypeID;
using EntityID = ObjectID;

using SystemTypeID = TypeID;
using SystemID = ObjectID;

using SystemPriority = u_int16_t;

static const TypeID INITIAL_TYPE_ID = 0;
static const ObjectID INITIAL_OBJECT_ID = 0;

static const ObjectID INVALID_OBJECT_ID = std::numeric_limits<ObjectID>::max();
static const TypeID INVALID_TYPE_ID = std::numeric_limits<TypeID>::max();

}

#endif //ROGUELIKE_PLATFORM_H
