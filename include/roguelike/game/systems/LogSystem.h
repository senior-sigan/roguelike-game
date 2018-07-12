/**
 * Created by Илья Сиганов on 12.07.2018.
 */

#ifndef ROGUELIKE_LOGSYSTEM_H
#define ROGUELIKE_LOGSYSTEM_H

#include <ECS/system/IteratingSystem.h>
#include <game/components/LogComponent.h>
#include <game/events/LogEvent.h>
#include <list>
#include <string>

class LogSystem : public ECS::IteratingSystem {
  std::list<std::string> buffer;

 public:
  void OnCreated() override {
    GetEventListener()->RegisterListener<LogSystem, LogEvent>(this, &LogSystem::OnLogEvent);
  }

  void ProcessEntity(const ECS::IEntityPtr &entity, f64 dt) override {
    auto lc = entity->GetComponent<LogComponent>();
    while (!buffer.empty()) {
      lc->Append(buffer.front());
      buffer.pop_front();
    }
  }

  void OnDestroy() override {
    GetEventListener()->UnregisterListener<LogSystem, LogEvent>(&LogSystem::OnLogEvent);
  }

  void OnLogEvent(const std::shared_ptr<LogEvent> &event) {
    buffer.push_back(event->GetText());
  }

  bool FamilyFilter(const ECS::IEntityPtr &entity) const override {
    return entity->HasComponent<LogComponent>();
  }
};

#endif  // ROGUELIKE_LOGSYSTEM_H
