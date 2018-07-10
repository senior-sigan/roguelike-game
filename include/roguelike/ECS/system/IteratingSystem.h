/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_ITERATINGSYSTEM_H
#define ROGUELIKE_ITERATINGSYSTEM_H

#include <ECS/EntityManager.h>
#include <ECS/system/ISystem.h>
namespace ECS {
class IteratingSystem : public ISystem {
  friend class SystemManager;

  void _PreUpdate(f64 dt) override;
  void _Update(f64 dt) override;
  void _PostUpdate(f64 dt) override;

 public:
  virtual void PreUpdate(f64 dt) {}
  virtual void Update(f64 dt) {}
  virtual void PostUpdate(f64 dt) {}

  virtual void PreProcessEntity(const IEntityPtr &entity, f64 dt) {}
  virtual void ProcessEntity(const IEntityPtr &entity, f64 dt) {}
  virtual void PostProcessEntity(const IEntityPtr &entity, f64 dt) {}

  /**
   * Filter and pass only IEntities that satisfy the predicate.
   * @return true if satisfy and false otherwise.
   */
  virtual bool FamilyFilter(const IEntityPtr &entity) const {
    return false;
  }
};
}
#endif  // ROGUELIKE_ITERATINGSYSTEM_H
