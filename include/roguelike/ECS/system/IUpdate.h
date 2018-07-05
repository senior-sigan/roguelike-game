/**
 * Created by Илья Сиганов on 15.06.2018.
 */

#ifndef ROGUELIKE_IUPDATEABLE_H
#define ROGUELIKE_IUPDATEABLE_H

class IUpdate {
  friend class SystemManager;

 protected:
  virtual void _PreUpdate(double dt) = 0;
  virtual void _Update(double dt) = 0;
  virtual void _PostUpdate(double dt) = 0;
};

#endif  // ROGUELIKE_IUPDATEABLE_H
