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

  void _PreUpdate(double dt) override;
  void _Update(double dt) override;
  void _PostUpdate(double dt) override;

 public:
  virtual void PreUpdate(double dt) {}
  virtual void Update(double dt) {}
  virtual void PostUpdate(double dt) {}

  virtual void PreProcessEntity(const IEntityPtr &entity, double dt) {}
  virtual void ProcessEntity(const IEntityPtr &entity, double dt) {}
  virtual void PostProcessEntity(const IEntityPtr &entity, double dt) {}

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
