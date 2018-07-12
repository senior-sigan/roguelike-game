/**
 * Created by Илья Сиганов on 11.07.2018.
 */

#ifndef ROGUELIKE_LOGCOMPONENT_H
#define ROGUELIKE_LOGCOMPONENT_H

#include <ECS/IComponent.h>
#include <core/types.h>
#include <list>
#include <string>

/**
 * Component store lines of text in a fixed size queue.
 */
class LogComponent : public ECS::IComponent {
  std::list<std::string> log;
  u32 max_size;

 public:
  const ECS::EntityID targetID;

  explicit LogComponent(u32 max_size, const ECS::EntityID targetID) : max_size(max_size), targetID(targetID) {}

  void Append(const std::string &text) {
    if (log.size() >= max_size) {
      log.pop_front();
    }
    log.push_back(text);
  }

  const std::list<std::string> Get() const {
    return log;
  }
};

#endif  // ROGUELIKE_LOGCOMPONENT_H
