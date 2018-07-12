#include <utility>

/**
 * Created by Илья Сиганов on 12.07.2018.
 */

#ifndef ROGUELIKE_LOGEVENT_H
#define ROGUELIKE_LOGEVENT_H

#include <string>
#include <ECS/Event/IEvent.h>

class LogEvent : public ECS::Event::IEvent {
  std::string text;

 public:
  explicit LogEvent(std::string text) : text(std::move(text)) {}

  std::string GetText() const {
    return text;
  }
};

#endif  // ROGUELIKE_LOGEVENT_H
