/**
 * Created by Илья Сиганов on 26.05.2018.
 */

#include "FamilyTypeID.h"

namespace ECS {

class IEntity;
class IComponent;
class ISystem;

namespace Internal {

template<>
TypeID FamilyTypeID<IEntity>::count = INITIAL_TYPE_ID;
template<>
TypeID FamilyTypeID<IComponent>::count = INITIAL_TYPE_ID;
template<>
TypeID FamilyTypeID<ISystem>::count = INITIAL_TYPE_ID;

template
class ECS::Internal::FamilyTypeID<IEntity>;

template
class ECS::Internal::FamilyTypeID<IComponent>;

template
class ECS::Internal::FamilyTypeID<ISystem>;
}
}