/**
 * Created by Илья Сиганов on 11.07.2018.
 */

#ifndef ROGUELIKE_LOGCOMPONENT_H
#define ROGUELIKE_LOGCOMPONENT_H

#include <ECS/IComponent.h>
#include <core/types.h>
#include <queue>
#include <string>

/**
 * Component store lines of text in a fixed size queue.
 */
class LogComponent : public ECS::IComponent {
  std::queue<std::string> log;
  u32 max_size;

 public:
  void Append(const std::string &text) {
    if (log.size() >= max_size) {
      log.pop();
    }
    log.push(text);
  }

  const std::queue<std::string> Get() const {
    return log;
  }
};

#endif  // ROGUELIKE_LOGCOMPONENT_H
