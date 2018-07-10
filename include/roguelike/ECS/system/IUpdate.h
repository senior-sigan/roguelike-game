/**
 * Created by Илья Сиганов on 15.06.2018.
 */

#ifndef ROGUELIKE_IUPDATEABLE_H
#define ROGUELIKE_IUPDATEABLE_H

class IUpdate {
  friend class SystemManager;

 protected:
  virtual void _PreUpdate(f64 dt) = 0;
  virtual void _Update(f64 dt) = 0;
  virtual void _PostUpdate(f64 dt) = 0;
 public:
  virtual ~IUpdate() = default;
};

#endif  // ROGUELIKE_IUPDATEABLE_H
