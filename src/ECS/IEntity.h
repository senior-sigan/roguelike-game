/**
 * Created by Илья Сиганов on 25.05.2018.
 */

#ifndef ROGUELIKE_IENTITY_H
#define ROGUELIKE_IENTITY_H

#include "Platform.h"
namespace ECS {

using EntityTypeID = TypeID;
using EntityID = ObjectID;

class IEntity {
 public:
  virtual const EntityTypeID GetTypeID() const = 0;

  virtual const EntityID GetID() const = 0;

  template<class C>
  virtual C *GetComponent() = 0;

  template<class C, class ...P>
  virtual C *AddComponent(P &&... params) = 0;

  template<class C>
  virtual void RemoveComponent() = 0;
};
}

#endif //ROGUELIKE_IENTITY_H
