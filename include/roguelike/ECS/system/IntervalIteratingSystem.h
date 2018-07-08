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
  const double interval;
  double currentTime;

  void _PreUpdate(double dt) override;
  void _Update(double dt) override;
  void _PostUpdate(double dt) override;

  void _PreUpdateInterval(double dt);
  void _UpdateInterval(double dt);
  void _PostUpdateInterval(double dt);

 public:
  explicit IntervalIteratingSystem(double interval);

  virtual void PreUpdate(double dt) {}
  virtual void Update(double dt) {}
  virtual void PostUpdate(double dt) {}

  virtual void PreProcessEntity(const IEntityPtr &entity, double dt) {}
  virtual void ProcessEntity(const IEntityPtr &entity, double dt) {}
  virtual void PostProcessEntity(const IEntityPtr &entity, double dt) {}

  virtual void PreUpdateInterval(double dt) {}
  virtual void UpdateInterval(double dt) {}
  virtual void PostUpdateInterval(double dt) {}

  virtual void PreProcessEntityInterval(const IEntityPtr &entity, double dt) {}
  virtual void ProcessEntityInterval(const IEntityPtr &entity, double dt) {}
  virtual void PostProcessEntityInterval(const IEntityPtr &entity, double dt) {}

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
