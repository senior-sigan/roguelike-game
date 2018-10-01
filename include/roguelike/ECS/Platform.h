/**
 * Created by Илья Сиганов on 25.05.2018.
 *
 * Used to define some types aliases, platform specific code.
 */

#ifndef ROGUELIKE_PLATFORM_H
#define ROGUELIKE_PLATFORM_H

#include <cstdio>
#include <limits>
#include <memory>
#include <typeindex>
#include <typeinfo>

namespace ECS {

using ObjectID = size_t;
using TypeID = std::type_index;

using EventTypeID = std::type_index;

using EventDelegateID = ObjectID;
using EventDelegateTypeID = TypeID;

using ComponentTypeID = TypeID;
using ComponentID = ObjectID;

using EntityTypeID = TypeID;
using EntityID = ObjectID;

using SystemTypeID = TypeID;
using SystemID = ObjectID;

using SystemPriority = size_t;

static const ObjectID INITIAL_OBJECT_ID = 0;

static const ObjectID INVALID_OBJECT_ID = std::numeric_limits<ObjectID>::max();

}

#endif  // ROGUELIKE_PLATFORM_H
