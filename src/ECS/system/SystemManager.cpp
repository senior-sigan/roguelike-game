/**
 * Created by Илья Сиганов on 03.06.2018.
 */

#include <ECS/EntityManager.h>
#include <ECS/system/SystemManager.h>

namespace ECS {
SystemManager::SystemManager(EntityManager *entityManager,
                             Event::EventDispatcher *eventDispatcher,
                             IEngineControl *engineControl1) :
    entityManager(entityManager), eventDispatcher(eventDispatcher), engineControl(engineControl1) {
    LOG_INFO("SystemManager was initialized");
}

SystemManager::~SystemManager() {
    container.clear();
}

void SystemManager::Update(double delta) {
    // TODO: iterate over systems with some order which is set by priority property.

    for (std::pair<SystemTypeID, ISystem *> system: container) {
        system.second->PreUpdate(delta);
    }

    for (std::pair<SystemTypeID, ISystem *> system: container) {
        system.second->Update(delta);
    }

    for (std::pair<SystemTypeID, ISystem *> system: container) {
        system.second->PostUpdate(delta);
    }
}
}