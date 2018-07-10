/**
 * Created by Илья Сиганов on 04.06.2018.
 */

#ifndef ROGUELIKE_INTERVALITERATINGSYSTEM_H
#define ROGUELIKE_INTERVALITERATINGSYSTEM_H

#include <ECS/EntityManager.h>
#include <ECS/system/ISystem.h>
namespace ECS {

/**
 * It's a combination of interval and iterating systems.
 */
class IntervalIteratingSystem : public ISystem {
  friend class SystemManager;
  const f64 interval;
  f64 currentTime;

  void _PreUpdate(f64 dt) override;
  void _Update(f64 dt) override;
  void _PostUpdate(f64 dt) override;

  void _PreUpdateInterval(f64 dt);
  void _UpdateInterval(f64 dt);
  void _PostUpdateInterval(f64 dt);

 public:
  explicit IntervalIteratingSystem(f64 interval);

  f64 GetCurrentTime() {
    return currentTime;
  }

  virtual void PreUpdate(f64 dt) {}
  virtual void Update(f64 dt) {}
  virtual void PostUpdate(f64 dt) {}

  virtual void PreProcessEntity(const IEntityPtr &entity, f64 dt) {}
  virtual void ProcessEntity(const IEntityPtr &entity, f64 dt) {}
  virtual void PostProcessEntity(const IEntityPtr &entity, f64 dt) {}

  virtual void PreUpdateInterval(f64 dt) {}
  virtual void UpdateInterval(f64 dt) {}
  virtual void PostUpdateInterval(f64 dt) {}

  virtual void PreProcessEntityInterval(const IEntityPtr &entity, f64 dt) {}
  virtual void ProcessEntityInterval(const IEntityPtr &entity, f64 dt) {}
  virtual void PostProcessEntityInterval(const IEntityPtr &entity, f64 dt) {}

  /**
   * Filter and pass only IEntities that satisfy the predicate.
   * @return true if satisfy and false otherwise.
   */
  virtual bool FamilyFilter(const IEntityPtr &entity) const {
    return false;
  }
};
}

#endif  // ROGUELIKE_INTERVALITERATINGSYSTEM_H
